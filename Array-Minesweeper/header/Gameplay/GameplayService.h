#pragma once

namespace Gameplay
{
	class GameplayController;
	enum class GameResult;
	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;
		void destroy();

	public:
		GameplayService();
		~GameplayService();
		void initialize();
		void update();
		void render();

		void startGame();
		int getRemainingNumberOfMines();
		float getRemainingTime();
		void endGame(GameResult result);

		GameResult getGameResult();
	};
}