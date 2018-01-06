#ifndef COMMON_UTILITIES_H
#define COMMON_UTILITIES_H

#include <string>

#include <StarterConfig.h>

class CommonUtilities {
	public:
		CommonUtilities() {}
		~CommonUtilities() {}

		static const char* getFullPath(std::string relativePath);
};

#endif // !COMMON_UTILITIES_H

