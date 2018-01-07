#include "ResourceManager.h"

ResourceManager* ResourceManager::GetInstance() {
	if (!resMgrInstance) {
		resMgrInstance = new ResourceManager();
	}

	return resMgrInstance;
}

Shader ResourceManager::loadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name) {
	shaders[name] = this->resImpl->loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return shaders[name];
}

Shader ResourceManager::getShader(std::string name) {
	return shaders[name];
}

Texture2D ResourceManager::loadTexture(const GLchar *file, GLboolean alpha, std::string name) {
	textures[name] = this->resImpl->loadTextureFromFile(file, alpha);
	return textures[name];
}

Texture2D ResourceManager::getTexture(std::string name) {
	return textures[name];
}

void ResourceManager::clear() {
	for (auto shader : shaders) {
		glDeleteProgram(shader.second.getShaderID());
	}
	for (auto texture : textures) {
		auto textureID = texture.second.getTextureID();
		glDeleteTextures(1, &textureID);
	}
}

ResourceManager::ResourceManager() {
	if (resImpl == nullptr) {
		resImpl = new ResourceImpl();
	}
}

ResourceManager::~ResourceManager() {
	delete resImpl;
	delete audioImpl;
}

ResourceManager* ResourceManager::resMgrInstance;