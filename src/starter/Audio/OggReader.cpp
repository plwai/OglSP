#include "Audio/OggReader.h"

#include <iostream>
#include <cstdio>

OggReader::OggReader() {
	
}

OggReader::~OggReader() {
	delete this->vorbisInfo;
}

bool OggReader::open(std::string filePath) {
	FILE* filePointer;
	fopen_s(&filePointer, filePath.c_str(), "rb");

	if (filePointer == NULL) {
		std::cout << "OggReader::ERROR::Failed to open audio file: " + filePath << std::endl;
		return false;
	}

	if (ov_open_callbacks(filePointer, &this->vorbisFile, NULL, 0, OV_CALLBACKS_DEFAULT) < 0) {
		std::cout << "OggReader::ERROR::Wrong input audio file format" << std::endl;
		return false;
	}

	this->vorbisInfo = ov_info(&this->vorbisFile, -1);

	return true;
}

int OggReader::readPcmData(std::string* pcmStream) {
	short eof = 0;
	int currentSection;
	char pcmData[4096];
	unsigned long bytesDone = 0;

	long bufferSize = this->getSamplingrate();
	bufferSize -= bufferSize % 4;
	
	while (!eof) {
		long ret = ov_read(&this->vorbisFile, pcmData, sizeof(pcmData), 0, 2, 1, &currentSection);

		if (ret == 0) {
			eof = 1;
		}
		else if (ret < 0) {
			std::cout << "OggReader::WARNING::stream error" << std::endl;
		}
		else {
			bytesDone += ret;


			pcmStream->append(pcmData, ret);
		}
	}

	return bytesDone;
}

void OggReader::clear() {
	ov_clear(&this->vorbisFile);
}

int OggReader::getChannel() {
	return this->vorbisInfo->channels;
}

long OggReader::getBitrate() {
	return this->vorbisInfo->bitrate_nominal;
}

long OggReader::getSamplingrate() {
	return this->vorbisInfo->rate;
}