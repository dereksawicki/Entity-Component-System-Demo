#ifndef AUDIO_H
#define AUDIO_H

#include <queue>

class Audio
{
public:
	enum SOUND_ID {
		node_selected,
	};

	enum MUSIC_ID {
		song_a,
		song_b,
		song_c
	};

public:
	Audio& getInstance();

	void update();

private:
	Audio();
	~Audio();

private:
	Audio* mInstance;
	std::queue<SOUND_ID> mPending;

};

#endif