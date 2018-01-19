#include "Audio/Audio.h"

#include <iostream>
#include <fstream>

Audio::Audio(ALuint bufferID) 
	: bufferID(bufferID) {
	this->sourceID = 0;
}

Audio::~Audio() {
	this->clearSource();
}

void Audio::generate() {
	// Generate Source
	if (this->sourceID == 0) {
		alGenSources((ALuint)1, &this->sourceID);
		this->checkError();

		alSourcef(this->sourceID, AL_PITCH, 1);
		this->checkError();

		alSourcef(this->sourceID, AL_GAIN, 1);
		this->checkError();

		alSource3f(this->sourceID, AL_POSITION, 0, 0, 0);
		this->checkError();

		alSource3f(this->sourceID, AL_VELOCITY, 0, 0, 0);
		this->checkError();

		alSourcei(this->sourceID, AL_BUFFER, this->bufferID);
		this->duration = getBufferLength(this->bufferID);
	}
}

void Audio::destroy() {
	// Clear all
	this->clear();
}

ALuint Audio::getSourceID() {
	return this->sourceID;
}

ALuint Audio::getBufferID() {
	return this->bufferID;
}

ALfloat Audio::getDuration() {
	return this->duration;
}

void Audio::setSourceID(ALuint sourceID) {
	this->sourceID = sourceID;
}

void Audio::setBufferID(ALuint bufferID) {
	this->bufferID = bufferID;
}

void Audio::setDuration(ALfloat duration) {
	this->duration = duration;
}

bool Audio::isPlaying() {
	ALenum state;

	alGetSourcei(this->sourceID, AL_SOURCE_STATE, &state);

	return (state == AL_PLAYING);
}

void Audio::clearSource() {
	// Clear all source
	if (this->sourceID != 0) {
		alDeleteSources(1, &this->sourceID);
		this->sourceID = 0;
	}
}

void Audio::clear() {
	this->clearSource();

	alDeleteBuffers(1, &this->bufferID);
	this->bufferID = 0;
}

bool Audio::checkError() {
	ALCenum error = alGetError();

	if (error != AL_NO_ERROR) {
		std::cout << "Audio::ERROR CODE:: " << error << std::endl;
		return true;
	}
	return false;
}

bool Audio::isStopped() {
	ALenum state;

	alGetSourcei(this->sourceID, AL_SOURCE_STATE, &state);

	return (state == AL_STOPPED);
}

ALfloat Audio::getBufferLength(ALuint buffer) {
	ALint size, bits, channels, freq;

	alGetBufferi(buffer, AL_SIZE, &size);
	alGetBufferi(buffer, AL_BITS, &bits);
	alGetBufferi(buffer, AL_CHANNELS, &channels);
	alGetBufferi(buffer, AL_FREQUENCY, &freq);
	if (alGetError() != AL_NO_ERROR)
		return -1.0f;

	return (ALfloat)((ALuint)size / channels / (bits / 8)) / (ALfloat)freq;
}