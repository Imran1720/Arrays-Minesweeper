#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;

namespace Gameplay
{
	namespace Cell
	{
		
		CellController::CellController(int row_index,int col_index)
		{
			cell_model = new CellModel(row_index,col_index);
			cell_view = new CellView(this);
		}
		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize(float width,float height)
		{
			cell_view->initialize(width,height);
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::render()
		{
			cell_view->render();
		}

		void CellController::setCellValue(CellValue value)
		{
			cell_model->setCellValue(value);
		}

		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}

		void CellController::setCellState(CellState state)
		{
			cell_model->setCellState(state);
		}

		CellState CellController::getCellState()
		{
			return cell_model->getCellState();
		}

		void CellController::SetCellPosition(Vector2f position)
		{
			cell_model->setCellPosition(position);
		}

		Vector2f CellController::getCellPosition()
		{
			return cell_model->getCellPosition();
		}

		void CellController::reset()
		{
			cell_model->reset();
		}

		Vector2i CellController::getCellIndex()
		{
			return cell_model->getCellIndex();
		}

		void CellController::openCell()
		{
			if (cell_model->getCellState() != CellState::FLAGGED)
			{
				cell_model->setCellState(CellState::OPEN);
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			}
		}

		void CellController::flagCell()
		{
			switch (cell_model->getCellState())
			{
			case CellState::FLAGGED:
				setCellState(CellState::HIDDEN);
				break;

			case CellState::HIDDEN:
				setCellState(CellState::FLAGGED);
				break;
			}
		}


		

		

		void CellController::destroy()
		{
			delete(cell_model);
			delete(cell_view);
		}

	}
}