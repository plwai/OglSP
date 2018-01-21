#include "CommonUtilities.h"

std::string CommonUtilities::getFullPath(std::string relativePath) {
	std::string result = "./" + relativePath;

	return result;
}