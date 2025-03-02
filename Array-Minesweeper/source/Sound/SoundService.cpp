#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"

#include <iostream>
using namespace std;

namespace Sound
{
	using namespace Global;

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path))
			printf("Error loading background music file");
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
			printf("Error loading background music file");

		if (!buffer_game_won.loadFromFile(Config::game_won_sound_path))
			printf("Error loading background music file");

		if (!buffer_explosion.loadFromFile(Config::explosion_sound_path))
			printf("Error loading background music file");

		if (!buffer_flag.loadFromFile(Config::flag_sound_path))
			printf("Error loading background music file");
	}

	void SoundService::playSound(SoundType soundType)
	{
		sound_type = soundType;
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			break;
		case SoundType::GAME_WON:
			sound_effect.setBuffer(buffer_game_won);
			break;
		case SoundType::EXPLOSION:
			sound_effect.setBuffer(buffer_explosion);
			break;
		case SoundType::FLAG_SOUND:
			
			sound_effect.setBuffer(buffer_flag);
			break;
		default:
			printf("Invalid sound type");
			return;
		}

		sound_effect.play();
	}

	void SoundService::playBackgroundMusic()
	{
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}
	
}