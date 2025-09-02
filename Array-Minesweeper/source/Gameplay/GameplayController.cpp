#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;
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

	void GameplayController::destroy()
	{
	}

}