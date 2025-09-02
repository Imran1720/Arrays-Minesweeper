#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/GameplayService.h"

using namespace Event;
using namespace Graphics;
using namespace Sound;
using namespace Time;
using namespace UI;
using namespace Gameplay;
using namespace Gameplay::GameplayUI;
using namespace Gameplay::Board;

namespace Global
{
    class ServiceLocator
    {
    private:
        EventService* event_service;
        GraphicService* graphic_service;
        TimeService* time_service;
        SoundService* sound_service;
        UIService* ui_service;
        BoardService* board_service;
        GameplayService* gameplay_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        EventService* getEventService();
        GraphicService* getGraphicService();
        SoundService* getSoundService();
        UIService* getUIService();
        BoardService* getBoardService();
        GameplayService* getGameplayService();
        TimeService* getTimeService();

        void deleteServiceLocator();
    };
}