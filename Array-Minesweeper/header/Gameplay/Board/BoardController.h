#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Board/BoardModel.h"

using namespace Gameplay::Cell;

namespace Gameplay
{
	namespace Board
	{
		class BoardView;
		class BoardController
		{
		private:
			int number_of_columns;
			int number_of_rows;

			BoardView* board_view;
			BoardModel* board_model;

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
			void reset();

		};
	}
}
