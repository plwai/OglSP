#ifndef DECODER_H
#define DECODER_H

#include <sstream>

class Decoder {
	public:
		Decoder() {};
		~Decoder() {};

		virtual bool open(std::string filePath) = 0;
		virtual int readPcmData(std::string* pcmStream) = 0;
		virtual void clear() = 0;

		virtual int getChannel() = 0;
		virtual long getBitrate() = 0;
		virtual long getSamplingrate() = 0;

	private:
		
};

#endif // !DECODER_H

