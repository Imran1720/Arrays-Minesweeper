#pragma once

namespace Gameplay
{
	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	private :
		const float max_duration= 10.f;
		float remaining_time;
		const float game_over_time = 11.f;
		GameResult game_result = GameResult::NONE;
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

		void endGame(GameResult result);
		void gameWon();
		void gameLost();
		void beginGameOverTimer();
		void showCredits();
		bool isTimeOver();

	};
}