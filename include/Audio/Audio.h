#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <map>
#include <vector>

#include <al.h>
#include <alc.h>
#include <efx.h>
#include <efx-creative.h>
#include <xram.h>

#include "Decoder.h"
#include "OggReader.h"

class Audio {
	public:
		Audio() {}
		Audio(ALuint bufferID);
		~Audio();

		void generate();
		void destroy();
		void clearSource();

		ALuint getSourceID();
		ALuint getBufferID();
		ALfloat getDuration();

		void setSourceID(ALuint sourceID);
		void setBufferID(ALuint bufferID);
		void setDuration(ALfloat duration);

		bool isPlaying();
		bool isStopped();

	private:
		ALuint sourceID;
		ALuint bufferID;
		ALfloat duration;
		
		void clear();

		bool checkError();

		static ALfloat getBufferLength(ALuint buffer);
};

#endif // !AUDIO_H