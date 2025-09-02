#include "../../header/UI/UIElement/ButtonView.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace UI::UIElement;

namespace Gameplay
{
	namespace Cell
	{
		class CellController;

		class CellView
		{
		private :
			CellController* cell_controller;
			ButtonView* cell_button;

			float tile_size = 32;
			float cell_width ;
			float cell_height ;
			int slice_count = 12;

			float cell_top_offset = 274.f;
			float cell_left_offset = 574.f;

			void destroy();
			
		public:
			CellView(CellController* controller);
			~CellView();

			void initialize(float width, float height);
			void update();
			void render();


			void initializeCellButton(float width, float height);
			void SetCellTexture();
			Vector2f getCellPosition(float width, float height);

			void registerButtonCallback();

			void cellButtonCallback(ButtonType button_type);

		};
	}
}