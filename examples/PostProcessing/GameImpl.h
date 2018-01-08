#ifndef GAMEIMPL_H
#define GAMEIMPL_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glfw/glfw3.h>

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include <ResourceManager.h>
#include <CommonUtilities.h>
#include <Renderer2D.h>
#include <SpriteRenderer.h>
#include <BoxObject.h>
#include "PostProcessor.h"

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
};

struct Screen {
	GLuint width;
	GLuint height;
};

class GameImpl {
	public:
		GameImpl();
		~GameImpl();

		void initLevel();
		void renderLevel(Renderer2D* renderer);

		std::vector<BoxObject*> getBoxCollection() const;

		void setBoxCollection(std::vector<BoxObject*> boxesCollection);

	private:
		std::vector<BoxObject*> boxesCollection;
		ResourceManager* resMgr;
};

#endif // !GAMEIMPL_H