#ifndef GAMEIMPL_H
#define GAMEIMPL_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glfw/glfw3.h>

#include <string>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "ResourceManager.h"
#include "CommonUtilities.h"
#include "SpriteRenderer.h"

struct Screen {
	GLuint width;
	GLuint height;
};

class GameImpl {
	public:
		GameImpl(GLuint width, GLuint height);
		~GameImpl();

		// Acessors
		Screen getScreen() const;

		// Mutators
		void setScreen(GLuint width, GLuint height);

	private:
		Screen screen;
		ResourceManager* resMgr;
};

#endif // !GAMEIMPL_H