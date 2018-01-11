#ifndef OGG_READER_H
#define OGG_READER_H

#include <string>
#include <sstream>

#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>

#include "Decoder.h"

class OggReader : public Decoder {
	public:
		OggReader();
		~OggReader();

		bool open(std::string filePath);
		int readPcmData(std::string* pcmStream);
		void clear();

		int getChannel();
		long getBitrate();
		long getSamplingrate();

	private:
		OggVorbis_File vorbisFile;
		vorbis_info* vorbisInfo;
};

#endif // !OGG_READER_H

