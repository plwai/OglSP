#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <map>

#include <glad/glad.h>

#include "ResourceImpl.h"
#include "Texture2D.h"
#include "Shader.h"
#include "Audio.h"

class ResourceManager {
	public:
		static ResourceManager* GetInstance();

		Shader loadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
		Shader getShader(std::string name);

		Texture2D loadTexture(const GLchar *file, GLboolean alpha, std::string name);
		Texture2D getTexture(std::string name);

		void clear();

	private:
		ResourceManager();
		~ResourceManager();
		ResourceImpl* resImpl;
		Audio* audioImpl;
		std::map<std::string, Shader> shaders;
		std::map<std::string, Texture2D> textures;
		static ResourceManager* resMgrInstance;
};

#endif // !RESOURCE_MANAGER_H
