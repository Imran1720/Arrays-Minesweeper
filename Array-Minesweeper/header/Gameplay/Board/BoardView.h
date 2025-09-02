#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

using namespace sf;
using namespace UI::UIElement;

namespace Gameplay
{
	namespace Board
	{
		class BoardController;
		class BoardView
		{
		private:
			BoardController* board_controller;
			RenderWindow* game_window;
			ImageView* background_image;
			ImageView* board_image;

			float background_image_alpha = 110.f;
			float board_width = 900.f;
			float board_height = 1080.f;

			float board_width_offset = 128.f;
			float board_height_offset = 329.f;

			void initializeBackgroundImage();
			void initializeBoardImage();
			void createImages();
			void destroy();

		public:


			BoardView(BoardController* controller);
			~BoardView();

			void initialize();
			void update();
			void render();

			void updateImages();
			void renderImages();
			float getBoardWidth();
			float getBoardHeight();
			
		};
	}
}