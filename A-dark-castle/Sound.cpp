#include "Sound.h"

void InitSound(StructMusic& music)
{
	music.prev_stage = 0;
	music.main_menu.openFromFile(music.sound_files[0] + music.sound_files[1]);
	music.exploration.openFromFile(music.sound_files[0] + music.sound_files[2]);
	music.battle.openFromFile(music.sound_files[0] + music.sound_files[3]);
	music.shop.openFromFile(music.sound_files[0] + music.sound_files[4]);
	music.main_menu.setLoop(true);
	music.exploration.setLoop(true);
	music.battle.setLoop(true);
	music.shop.setLoop(true);
	music.main_menu.setVolume(50);	
	music.exploration.setVolume(50);
	music.battle.setVolume(50);
	music.shop.setVolume(50);
	music.main_menu.play();
	music.main_menu.setPlayingOffset(seconds(40));
}
void PlaySound(StructMusic& music, int stage_game)
{
	if (music.prev_stage != stage_game)
	{
		if (music.prev_stage == 0)
			music.main_menu.stop();
		if (music.prev_stage == 1)
			music.exploration.stop();
		if (music.prev_stage == 2)
			music.battle.stop();
		if (music.prev_stage == 3)
			music.shop.stop();

		if (stage_game == 0)
			music.main_menu.play();
		if (stage_game == 1)
			music.exploration.play();
		if (stage_game == 2)
			music.battle.play();
		if (stage_game == 3)
			music.shop.play();
	}
	music.prev_stage = stage_game;
}