#ifndef GAMEIMPL_H
#define GAMEIMPL_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glfw/glfw3.h>

#include <string>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include <ResourceManager.h>
#include <CommonUtilities.h>
#include <SpriteRenderer.h>
#include "PostProcessor.h"

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
		SpriteRenderer* getSpriteRenderer() const;
		PostProcessor* getPostProcessor() const;

		// Mutators
		void setScreen(GLuint width, GLuint height);
		void setSpriteRenderer(SpriteRenderer* renderer);
		void setPostProcessor(PostProcessor* effect);
		void setPostProcessor(Shader &shader);

	private:
		Screen screen;
		ResourceManager* resMgr;
		SpriteRenderer* spriteRenderer;
		PostProcessor* effect;
};

#endif // !GAMEIMPL_H