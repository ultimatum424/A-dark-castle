#include "Sound.h"

void InitSound(StructMusic& music)
{
	music.prev_stage = 0;
	music.road_play = 0;
	music.main_menu.openFromFile(music.sound_files[0] + music.sound_files[1]);
	music.exploration.openFromFile(music.sound_files[0] + music.sound_files[2]);
	music.battle.openFromFile(music.sound_files[0] + music.sound_files[3]);
	music.shop.openFromFile(music.sound_files[0] + music.sound_files[4]);
	music.campfire.openFromFile(music.sound_files[0] + music.sound_files[5]);
	music.old_road.openFromFile(music.sound_files[0] + music.sound_files[6]);
	music.main_menu.setLoop(true);
	music.exploration.setLoop(true);
	music.battle.setLoop(true);
	music.shop.setLoop(true);
	music.campfire.setLoop(true);
	music.main_menu.setVolume(50);	
	music.exploration.setVolume(50);
	music.battle.setVolume(50);
	music.shop.setVolume(50);
	music.campfire.setVolume(50);
	music.main_menu.play();
	music.main_menu.setPlayingOffset(seconds(40));
}
void PlaySound(StructMusic& music, int stage_game)
{
	if (music.prev_stage != stage_game)
	{
		if (music.prev_stage == 0)
		{
			music.main_menu.stop();
			music.old_road.stop();
		}
		if (music.prev_stage == 1)
			music.exploration.stop();
		if (music.prev_stage == 2)
			music.battle.stop();
		if (music.prev_stage == 3)
			music.shop.stop();
		if (music.prev_stage == 4)
			music.campfire.stop();

		if (stage_game == 0)
			music.main_menu.play();
		if (stage_game == 1)
			music.exploration.play();
		if (stage_game == 2)
			music.battle.play();
		if (stage_game == 3)
			music.shop.play();
		if (stage_game == 4)
			music.campfire.play();
	}
	music.prev_stage = stage_game;
}
void LoadSoundEffect(StructBuffer& sound, string file)
{
	sound.buffer.loadFromFile(file);
	sound.sound.setBuffer(sound.buffer);
}
void InitSoundEffects(StructSound& sound)
{
	LoadSoundEffect(sound.cheat, "../sound/effect/cheat.WAV");
	LoadSoundEffect(sound.eat, "../sound/effect/eat.WAV");
	LoadSoundEffect(sound.eat_fire, "../sound/effect/eat_fire.WAV");
	LoadSoundEffect(sound.click, "../sound/effect/click.WAV");
	LoadSoundEffect(sound.buff, "../sound/effect/bufl_2.WAV");
	LoadSoundEffect(sound.end_battle, "../sound/effect/end_battle.WAV");
	LoadSoundEffect(sound.enemy_attack, "../sound/effect/enemy_attack.WAV");
	LoadSoundEffect(sound.hill, "../sound/effect/hill.WAV");
	LoadSoundEffect(sound.knife, "../sound/effect/knife.WAV");
	LoadSoundEffect(sound.next_battle, "../sound/effect/start_battle.WAV");
	LoadSoundEffect(sound.pistol, "../sound/effect/shoot_pistol.WAV");
	LoadSoundEffect(sound.ranged_attack, "../sound/effect/knife-2.WAV");
}