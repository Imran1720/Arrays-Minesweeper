#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Cell/CellController.h"

using namespace Gameplay::Cell;

namespace Gameplay
{
	namespace Board
	{

		class BoardController;
		
		class BoardService
		{
		private:
			BoardController* board_controller;

			void destroy();

		public:


			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();

			int getNumberOfMines();
			void resetBoard();

			void processCellInput(CellController* cell_controller, ButtonType button_type);
			void showBoard();
			void setBoardState(BoardState state);
			void flagAllMines();
		};
	}
}