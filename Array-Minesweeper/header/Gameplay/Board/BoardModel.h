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
			static const int number_of_rows = 10;
			static const int number_of_columns = 10;
			static const int number_of_mines = number_of_columns+number_of_rows;

			BoardModel();
			~BoardModel();

			void initialize();
			void update();
			void render();
			void reset();
		};
	}
}