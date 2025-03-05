#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"


namespace Gameplay
{
    
    GameplayService::GameplayService()
    {
        gameplay_controller = new GameplayController();
    }

    GameplayService::~GameplayService()
    {
        destroy();
    }

    void GameplayService::initialize()
    {

        gameplay_controller->initialize();
    }

    void GameplayService::update()
    {
        gameplay_controller->update();
    }

    void GameplayService::render()
    {
        gameplay_controller->render();
    }

    void GameplayService::startGame()
    {
        gameplay_controller->reset();
    }

    int GameplayService::getRemainingNumberOfMines()
    {
        return gameplay_controller->getNumberOfMines();
    }

    float GameplayService::getRemainingTime()
    {
        return gameplay_controller->getRemainingTime();
    }

    void GameplayService::endGame(GameResult result)
    {
        gameplay_controller->endGame(result);
    }

    GameResult GameplayService::getGameResult()
    {
        return gameplay_controller->getGameResult();
    }

    void Gameplay::GameplayService::destroy()
    {
        delete(gameplay_controller);
    }
}