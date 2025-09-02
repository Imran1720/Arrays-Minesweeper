#pragma once

namespace Gameplay
{
	class GameplayController
	{
	private :
		const float max_duration= 301.f;
		float remaining_time;

		void destroy();

	public :
		GameplayController();
		~GameplayController();
		void initialize();
		void update();
		void render();

		void reset();
		float getRemainingTime();
		void restart();
		int getNumberOfMines();
		void updateRemainingTime();
	};
}