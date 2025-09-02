#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Board/BoardModel.h"


namespace Gameplay
{
	namespace Board
	{
		
		BoardController::BoardController()
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
			float width = board_view->getBoardWidth();
			float height = board_view->getBoardHeight();
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
			return BoardModel::number_of_mines;
		}

		void BoardController::reset()
		{
			//board_model->reset();

			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					cells[i][j]->reset();
				}
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