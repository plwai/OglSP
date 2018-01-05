#ifndef RESOURCE_IMPL_H
#define RESOURCE_IMPL_H

#include <glad/glad.h>

#include "Shader.h"
#include "Texture2D.h"

class ResourceImpl {
	public:
		ResourceImpl();
		Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
		Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
};

#endif // !RESOURCE_IMPL_H
