#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/UI/UIElement/ButtonView.h"


using namespace sf;
using namespace UI;

namespace Gameplay
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const int font_size = 110;
			const Color text_color = Color::Red;

			//time
			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;

			//Mine
			const float mine_text_top_offset = 65.f;
			const float mine_text_left_offset = 660.f;

			//restart button
			const float restart_button_top_offset = 100.f;
			const float restart_button_left_offset = 920.f;

			const float button_height = 80.f;
			const float button_width = 80.f;

			const int tile_height = 32;

			UIElement::TextView* time_text;
			UIElement::TextView* mine_text;
			UIElement::ButtonView* restart_button;


		public:
			GameplayUIController();
			~GameplayUIController();
			 void initialize() ;
			 void update() ;
			 void render() ;
			 void show();

			 void createTexts();
			 void createButton();
			 void initializeButton();
			 void initializeTexts();
			 void initializeTimeText();
			 void initializeMineText();

			 void   updateTimeText();
			 void updateMineText();

			 void registerButtonCallBack();
			 void restartButtonCallback();
			 void destroy();

		};
	}
}