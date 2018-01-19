#include "Audio/AudioEngine.h"

#include <iostream>
#include <fstream>

AudioEngine* AudioEngine::GetInstance() {
	if (!audioEngine) {
		audioEngine = new AudioEngine();
	}

	return audioEngine;
}

AudioEngine::AudioEngine() {
	this->init();
}

AudioEngine::~AudioEngine() {

}

void AudioEngine::loadAudio(std::string filePath, std::string fileName) {
	// Read Data from file
	Decoder* decoder;
	ALuint bufferID;

	// Generate New Buffer
	alGenBuffers((ALuint)1, &bufferID);
	this->checkError();

	std::ifstream file(filePath);
	if (!file.good()) {
		std::cout << "Audio::ERROR:: audio file not found" << std::endl;
		file.close();
		return;
	}

	std::string fileExtension = filePath.substr(filePath.rfind('.'));

	if (fileExtension.compare(".ogg") == 0) {
		decoder = new OggReader();
	}
	else {
		std::cout << "Audio::ERROR:: audio format not supported" << std::endl;
		return;
	}

	// Get PCM data
	std::string pcmStream;

	decoder->open(filePath);
	int writtenBufferSize = decoder->readPcmData(&pcmStream);

	// Bind Buffer
	alBufferData(bufferID, toAlFormat(decoder->getChannel(), 16), pcmStream.c_str(), writtenBufferSize, decoder->getSamplingrate());

	// Clear stream
	decoder->clear();

	Audio audio(bufferID);
	audioMap[fileName] = audio;
}

Audio AudioEngine::getAudio(std::string audioName) {
	return this->audioMap[audioName];
}

void AudioEngine::releaseAudio(std::string audioName) {
	if(this->audioMap.find(audioName) != this->audioMap.end()) {
		this->audioMap[audioName].destroy();
		this->audioMap.erase(audioName);
	}
}

void AudioEngine::play(Audio* audio, bool loop) {
	if (audio == NULL) {
		return;
	}
	audio->generate();
	alSourcei(audio->getSourceID(), AL_LOOPING, (ALboolean)loop);
	this->checkError();

	// Play Sound
	alSourcePlay(audio->getSourceID());
	this->checkError();
}

void AudioEngine::stop(Audio* audio) {
	alSourceStop(audio->getSourceID());
	this->checkError();
}

void AudioEngine::pause(Audio* audio) {
	alSourcePause(audio->getSourceID());
	this->checkError();
}

void AudioEngine::resume(Audio* audio) {
	alSourcePlay(audio->getSourceID());
	this->checkError();
}

void AudioEngine::rewind(Audio* audio) {
	alSourceRewind(audio->getSourceID());
	this->checkError();
}

void AudioEngine::update(Audio* audio, ALuint dt) {
	audio->setDuration(audio->getDuration() - dt);

	if (audio->getDuration() < 0) {
		if (audio->isStopped()) {
			audio->clearSource();
		}
		else {
			audio->setDuration(audio->getDuration() + dt);
		}
	}
}

void AudioEngine::destroy() {
	for (auto audio : this->audioMap) {
		audio.second.destroy();
	}

	alcMakeContextCurrent(NULL);
	alcDestroyContext(this->context);
	alcCloseDevice(this->device);
}

void AudioEngine::init() {
	this->device = alcOpenDevice(NULL);

	if (this->device) {
		this->context = alcCreateContext(this->device, NULL);

		if (!alcMakeContextCurrent(this->context)) {
			std::cout << "AudioEngine::ERROR:: Failed to make context" << std::endl;
		}
	}
	else {
		std::cout << "AudioEngine::ERROR:: Failed to open device" << std::endl;
	}

	this->checkError();
}


bool AudioEngine::checkError() {
	ALCenum error = alGetError();

	if (error != AL_NO_ERROR) {
		std::cout << "AudioEngine::ERROR CODE:: " << error << std::endl;
		return true;
	}
	return false;
}

ALenum AudioEngine::toAlFormat(short channels, short samples) {
	bool stereo = (channels > 1);

	switch (samples) {
		case 16:
			if (stereo)
				return AL_FORMAT_STEREO16;
			else
				return AL_FORMAT_MONO16;
		case 8:
			if (stereo)
				return AL_FORMAT_STEREO8;
			else
				return AL_FORMAT_MONO8;
		default:
			return -1;
	}
}

AudioEngine* AudioEngine::audioEngine;