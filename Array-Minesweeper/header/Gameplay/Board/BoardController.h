#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Board/BoardModel.h"

using namespace Gameplay::Cell;
using namespace sf;
namespace Gameplay
{
	namespace Board
	{
		enum class BoardState
		{
			FIRST_CELL,
			PLAYING,
			COMPLETED
		};

		class BoardView;
		class BoardController
		{
			
		private:
			int number_of_columns;
			int number_of_rows;
			int number_of_flags_available;
			int number_of_mines;

			std::default_random_engine random_engine;
			std::random_device random_device;

			BoardView* board_view;
			BoardModel* board_model;

			BoardState board_state;

			CellController* cells[BoardModel::number_of_rows][BoardModel::number_of_columns];

			void createBoard();
			void deleteBoard();
			void setCloumRowCount();
			void destroy();

		public:


			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();

			void renderBoard();
			void updateBoard();
			void initializeBoard(float width,float height);

			int getMineCount();
			void openCell(Vector2i cell_position);
			void openEmptyCell(Vector2i cell_position);
			void flagCell(Vector2i cell_position);
			void processCellInput(CellController* cell_controller, ButtonType button_type);
			void reset();

			BoardState getBoardState();
			void setBoardState(BoardState new_board_state);
			void populateBoard(Vector2i position);
			void populateCells(Vector2i position);
			void populateMines(Vector2i position);

			bool isValidCellPosition(Vector2i position);
			int countMinesAround(Vector2i cell_position);
			void openAllCells();
			void processCellValue(Vector2i position);
			void processEmptyCell(Vector2i position);
			void processMineCell(Vector2i position);

			void showBoard();
		};
	}
}
