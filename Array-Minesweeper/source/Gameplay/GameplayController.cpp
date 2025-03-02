#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

#include <iostream>
using namespace std;

using namespace Global;
using namespace Main;
namespace Gameplay
{
	
	GameplayController::GameplayController()
	{
	}

	GameplayController::~GameplayController()
	{
	}

	void GameplayController::initialize()
	{
	}

	void GameplayController::update()
	{
		updateRemainingTime();
		if (isTimeOver())
		{
			endGame(GameResult::LOST);
		}
	}

	void GameplayController::render()
	{
	}

	void GameplayController::reset()
	{
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
		restart();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}

	void GameplayController::restart()
	{
		remaining_time = max_duration;
	}

	int GameplayController::getNumberOfMines()
	{
		return ServiceLocator::getInstance()->getBoardService()->getNumberOfMines();
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); 

	}

	void GameplayController::endGame(GameResult result)
	{
		switch (result)
		{
		case GameResult::WON:
			gameWon();
			break;

		case GameResult::LOST:
			gameLost();
			break;
		}
	}

	void GameplayController::gameWon()
	{
	}

	void GameplayController::gameLost()
	{
		cout << (int)game_result << endl;
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;

			beginGameOverTimer();
			ServiceLocator::getInstance()->getBoardService()->showBoard();
			ServiceLocator::getInstance()->getBoardService()->setBoardState(BoardState::COMPLETED);

		}
		else
		{
			showCredits();
		}
	}

	void GameplayController::beginGameOverTimer()
	{
		remaining_time = game_over_time;
	}

	void GameplayController::showCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}

	bool GameplayController::isTimeOver()
	{
		return remaining_time<=0;
	}


	void GameplayController::destroy()
	{
	}

}