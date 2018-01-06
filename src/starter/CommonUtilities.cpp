#include "CommonUtilities.h"

const char* CommonUtilities::getFullPath(std::string relativePath) {
	std::string path = ROOT_PATH;

	return (path + relativePath).c_str();
}