#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Board/BoardModel.h"
#include "../../header/Global/ServiceLocator.h"

#include <iostream>
using namespace std;

using namespace Global;

namespace Gameplay
{
	namespace Board
	{
		
		BoardController::BoardController() : random_engine(random_device())
		{
			board_model = new BoardModel();
			board_view = new BoardView(this);
			setCloumRowCount();
			createBoard();
			
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			float width = board_view->CalculateCellWidth();
			float height = board_view->CalculateCellHeight();
			initializeBoard(width, height);
		}

		void BoardController::update()
		{
			board_view->update();
			updateBoard();
		}

		void BoardController::render()
		{
			board_view->render();
			renderBoard();
			
		}

		void BoardController::renderBoard()
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					cells[i][j]->render();
				}
			}
		}

		void BoardController::updateBoard()
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					cells[i][j]->update();
				}
			}
		}

		void BoardController::initializeBoard(float width, float height)
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					cells[i][j]->initialize(width,height);
				}
			}
		}

		

		int BoardController::getMineCount()
		{
			return number_of_flags_available>=0? number_of_flags_available:0;
		}

		void BoardController::openCell(Vector2i position)
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);

			if (cells[position.x][position.y]->canOpenCell())
			{
				if (board_state == BoardState::FIRST_CELL)
				{
					populateBoard(position);
					board_state = BoardState::PLAYING;
				}
				processCellValue(position);
				cells[position.x][position.y]->openCell();
			}

		}

		void BoardController::flagCell(Vector2i position)
		{
			switch (cells[position.x][position.y]->getCellState())
			{
			case CellState::FLAGGED:
				(number_of_flags_available<0)?number_of_flags_available=1:number_of_flags_available++;
				break;
			case CellState::HIDDEN:
				if (number_of_flags_available >= 0)
				{

					number_of_flags_available--;
				}
				break;
			}
			if (number_of_flags_available >= 0)
			{
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				cells[position.x][position.y]->flagCell();
			}
		}


		void BoardController::processCellInput(CellController* cell_controller, ButtonType button_type)
		{
			switch (button_type)
			{
			case ButtonType::LEFT_MOUSE_BUTTON:
				openCell(cell_controller->getCellIndex());
				break;

			case ButtonType::RIGHT_MOUSE_BUTTON:
				flagCell(cell_controller->getCellIndex());
				break;
			}
		}

		void BoardController::reset()
		{
			number_of_flags_available = BoardModel::number_of_mines;
			number_of_mines = number_of_flags_available;
			board_state = BoardState::FIRST_CELL;
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					cells[i][j]->reset();
				}
			}

			
		}

		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState new_board_state)
		{
			board_state = new_board_state;
		}

		void BoardController::populateBoard(Vector2i position)
		{
			populateMines(position);
			populateCells(position);
		}

		void BoardController::populateCells(Vector2i position)
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					if (cells[a][b]->getCellValue() != CellValue::MINE)
					{
						CellValue value = static_cast<CellValue>(countMinesAround(sf::Vector2i(a, b)));
						cells[a][b]->setCellValue(value);
					}
				}
			}
		}

		void BoardController::populateMines(Vector2i position)
		{
			std::uniform_int_distribution<int> xdistribution(0, number_of_columns - 1);
			std::uniform_int_distribution<int> ydistribution(0, number_of_rows - 1);

			for (int i = 0; i < number_of_mines; i++)
			{
				int row = static_cast<int>(ydistribution(random_engine));
				int col = static_cast<int>(xdistribution(random_engine));

				if ((cells[row][col]->getCellValue() == CellValue::MINE) || (position.x == row && position.y == col))
				{
					i--;
				}
				else
				{
					cells[row][col]->setCellValue(CellValue::MINE);
				}
			}
		}

		bool BoardController::isValidCellPosition(Vector2i cell_position)
		{
			return (cell_position.x >= 0 && cell_position.y >= 0 && cell_position.x < number_of_rows && cell_position.y < number_of_columns);
		}

		int BoardController::countMinesAround(Vector2i cell_position)
		{
			int mine_around = 0;
			for (int i = cell_position.x - 1; i < cell_position.x + 2; i++)
			{
				for (int j = cell_position.y - 1; j < cell_position.y + 2; j++)
				{
					if ((i == cell_position.x && j == cell_position.y) || !isValidCellPosition(Vector2i(i, j)))
					{
						continue;
					}

					if (cells[i][j]->getCellValue() == CellValue::MINE)
					{
						mine_around++;
					}
				}
			}

			return mine_around;
		}

		void BoardController::openAllCells()
		{

			if (board_state == BoardState::FIRST_CELL)
			{
				populateBoard(Vector2i(0, 0));
			}

			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					cells[i][j]->openCell();
				}
			}
		}

		void BoardController::processCellValue(Vector2i position)
		{
			switch (cells[position.x][position.y]->getCellValue())
			{
			case CellValue::EMPTY:
				break;

			case CellValue::MINE:
				break;
			default:ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				break;
			}
		}

		

		void BoardController::createBoard()
		{


			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					cells[i][j] =new CellController(i,j);
				}
			}
		}

		void BoardController::deleteBoard()
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					delete(cells[i][j]);
				}
			}
		}


		void BoardController::setCloumRowCount()
		{
			number_of_columns = BoardModel::number_of_columns;
			number_of_rows = BoardModel::number_of_rows;
		}

		void BoardController::destroy()
		{
			delete(board_model);
			delete(board_view);
			deleteBoard();
		}
	}
}