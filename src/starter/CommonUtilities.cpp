#include "CommonUtilities.h"

std::string CommonUtilities::getFullPath(std::string relativePath) {
	std::string path = OGLSP_ROOT_PATH;
	std::string result = path + "/" + relativePath;

	return result;
}