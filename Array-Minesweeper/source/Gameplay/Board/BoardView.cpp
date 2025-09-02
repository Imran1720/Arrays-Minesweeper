#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/Board/BoardModel.h"


using namespace Global;

namespace Gameplay
{
	namespace Board
	{
		
		BoardView::BoardView(BoardController* controller)
		{
			game_window = nullptr;
			board_controller = controller;
			createImages();
		}

		BoardView::~BoardView()
		{
			destroy();
		}

		void BoardView::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			initializeBackgroundImage();
			initializeBoardImage();
		}

		void BoardView::update()
		{
			updateImages();
		}

		void BoardView::render()
		{
			renderImages();
		}

		void BoardView::initializeBackgroundImage()
		{
			
			background_image->initialize(Config::background_texture_path,
				game_window->getSize().x,
				game_window->getSize().y,
				Vector2f(0, 0));
			background_image->setImageAlpha(background_image_alpha);
		}

		void BoardView::initializeBoardImage()
		{
			board_image->initialize(Config::board_texture_path, 
				board_width, 
				board_height, 
				Vector2f(0, 0));
			board_image->setCentreAlinged();
		}

		void BoardView::createImages()
		{
			background_image = new ImageView();
			board_image = new ImageView();
		}

		void BoardView::updateImages()
		{
			background_image->update();
			board_image->update();
		}

		void BoardView::renderImages()
		{
			background_image->render();
			board_image->render();
		}

		float BoardView::getBoardWidth()
		{
			float width =  (board_width-board_width_offset)/static_cast<float>(BoardModel::number_of_columns);
			return width;
		}


		float BoardView::getBoardHeight()
		{
			float height =  (board_height-board_height_offset)/static_cast<float>(BoardModel::number_of_rows);
			
			return height;
		}

		void BoardView::destroy()
		{
		}
	}
}