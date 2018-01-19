#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <map>
#include <string>

#include <al.h>
#include <alc.h>
#include <efx.h>
#include <efx-creative.h>
#include <xram.h>

#include "Audio.h"

class AudioEngine {
	public:
		static AudioEngine* GetInstance();

		void loadAudio(std::string filePath, std::string fileName); // Load audio file into buffer
		Audio getAudio(std::string audioName);
		void releaseAudio(std::string audioName);

		void play(Audio* audio, bool loop = false);
		void stop(Audio* audio);
		void pause(Audio* audio);
		void resume(Audio* audio);
		void rewind(Audio* audio);

		void update(Audio* audio, ALuint dt);

		void destroy();

	private:
		AudioEngine();
		~AudioEngine();

		std::map<std::string, Audio> audioMap;

		ALCdevice* device;
		ALCcontext* context;

		void init();
		bool checkError();

		static AudioEngine* audioEngine;
		static ALenum toAlFormat(short channels, short samples);
};

#endif // !AUDIO_ENGINE_H

