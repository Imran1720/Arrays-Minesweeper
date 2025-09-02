#include "../../header/UI/Gameplay/UI/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"


#include <sstream>
#include <iomanip>

#include <iostream>
using namespace std;
using namespace UIElement;

using namespace Global;

namespace Gameplay
{
	namespace GameplayUI
	{
		GameplayUIController::GameplayUIController()
		{
			createButton();
			createTexts();
		}
		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}
		void GameplayUIController::initialize()
		{
			initializeButton();
			initializeTexts();
		}
		void GameplayUIController::update()
		{
			restart_button->update();
			updateTimeText();
			updateMineText();
		}
		void GameplayUIController::render()
		{
			restart_button->render();
			time_text->render();
			mine_text->render();
		}
		void GameplayUIController::show()
		{
			restart_button->show();
			time_text->show();
			mine_text->show();
		}
		void GameplayUIController::createTexts()
		{
			time_text = new TextView();
			mine_text = new TextView();

		}
		void GameplayUIController::createButton()
		{
			restart_button = new ButtonView();
		}
		void GameplayUIController::initializeTexts()
		{
			initializeTimeText();
			initializeMineText();
		}
		void GameplayUIController::initializeButton()
		{
			restart_button->initialize("Restart Button",
				Config::restart_button_texture_path,
				button_width,
				button_height,
				Vector2f(restart_button_left_offset,restart_button_top_offset));
			registerButtonCallBack();
		}
		void GameplayUIController::initializeTimeText()
		{
			time_text->initialize("300",
				Vector2f(time_text_left_offset, time_text_top_offset),
				FontType::DS_DIGIB,
				font_size,
				text_color);
		}

		void GameplayUIController::initializeMineText()
		{
			mine_text->initialize("000",
				Vector2f(mine_text_left_offset, mine_text_top_offset),
				FontType::DS_DIGIB,
				font_size,
				text_color);
		}

		void GameplayUIController::updateTimeText()
		{
			int remaining_time = ServiceLocator::getInstance()->getGameplayService()->getRemainingTime();

			std::stringstream stream;

			stream << std::setw(3) << std::setfill('0') << remaining_time;
			std::string string_remaining_time = stream.str();

			time_text->setText(string_remaining_time);
			time_text->update();
		}

		void GameplayUIController::updateMineText()
		{
			int remaining_mines = ServiceLocator::getInstance()->getGameplayService()->getRemainingNumberOfMines();

			std::stringstream stream;

			stream << std::setw(3) << std::setfill('0') << remaining_mines;

			std::string string_remaining_mine = stream.str();

			mine_text->setText(string_remaining_mine);
			mine_text->update();
		}

		void GameplayUIController::registerButtonCallBack()
		{
			restart_button->registerCallbackFuntion(std::bind(&GameplayUIController::restartButtonCallback, this));
		}

		void GameplayUIController::restartButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getGameplayService()->startGame();
		}

		void GameplayUIController::destroy()
		{
			delete(restart_button);
			delete(time_text);
			delete(mine_text);
		}
	}
}