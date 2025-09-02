#pragma once


namespace Gameplay
{
	namespace Board
	{
		class BoardModel
		{
		private:

			void destroy();

		public:
			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int number_of_mines = 8;

			BoardModel();
			~BoardModel();

			void initialize();
			void update();
			void render();
			void reset();
		};
	}
}