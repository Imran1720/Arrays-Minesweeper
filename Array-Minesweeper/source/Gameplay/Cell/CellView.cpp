
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/Config.h"
#include <functional>
#include <iostream>
using namespace std;

using namespace sf;
using namespace Global;

namespace Gameplay
{
	namespace Cell
	{
		
		CellView::CellView(CellController* controller)
		{
			cell_controller = controller;
			cell_button = new ButtonView();
		}
		CellView::~CellView()
		{
			destroy();
		}

		void CellView::initialize(float width,float height)
		{
			initializeCellButton(width,height);
			registerButtonCallback();
		}

		void CellView::update()
		{
			SetCellTexture();
			cell_button->update();
		}

		void CellView::render()
		{
			cell_button->render();
		}

		void CellView::initializeCellButton(float width, float height)
		{
			cell_width = width;
			cell_height = height;
			SetCellTexture();
			cell_button->initialize("CELL",
				Config::cells_texture_path,
				cell_width * slice_count,
				cell_height,
				getCellPosition(cell_width,cell_height));
		}

		void CellView::SetCellTexture()
		{
			int index = static_cast<int>(cell_controller->getCellValue());
			switch (cell_controller->getCellState())
			{
			case CellState::HIDDEN:
				cell_button->setTextureRect(IntRect(10 * tile_size, 0, tile_size, tile_size));
				break;

			case CellState::OPEN:
				cell_button->setTextureRect(IntRect(index * tile_size, 0, tile_size, tile_size));
				break;

			case CellState::FLAGGED :
				cell_button->setTextureRect(IntRect(11 * tile_size, 0, tile_size, tile_size));
				break;
			}
		}

		Vector2f CellView::getCellPosition(float width,float height)
		{
			float xPosition = cell_left_offset + (width * cell_controller->getCellIndex().y);
			float yPosition = cell_top_offset+(height*cell_controller->getCellIndex().x);
			return Vector2f(xPosition,yPosition);
		}

		void CellView::registerButtonCallback()
		{
			cell_button->registerCallbackFuntion(std::bind(&CellView::cellButtonCallback, this, std::placeholders::_1));
		}

		void CellView::cellButtonCallback(ButtonType button_type)
		{
			switch (button_type)
			{
			case ButtonType::LEFT_MOUSE_BUTTON:
				cell_controller->openCell();
				break;

			case ButtonType::RIGHT_MOUSE_BUTTON:
				cell_controller->flagCell();
				break;
			}
		}

		


		

		void CellView::destroy()
		{
			delete(cell_controller);
		}
	}
}



