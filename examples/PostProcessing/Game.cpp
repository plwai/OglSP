#include "Game.h"

#include <CommonUtilities.h>

#include <iostream>

Game::Game(GLuint width, GLuint height) 
	: screen({width, height}) {
	if (gameImplementation == nullptr) {
		gameImplementation = new GameImpl();
	}

	resMgr = ResourceManager::GetInstance();
}

Game::~Game() {
	delete gameImplementation;
	delete spriteRenderer;
	delete effect;
}

void Game::init() {
	resMgr->loadShader(CommonUtilities::getFullPath("src/shaders/sprite.vert").c_str(), CommonUtilities::getFullPath("src/shaders/sprite.frag").c_str(), nullptr, "sprite");
	resMgr->loadShader(CommonUtilities::getFullPath("examples/PostProcessing/postProcess.vert").c_str(), CommonUtilities::getFullPath("examples/PostProcessing/postProcess.frag").c_str(), nullptr, "effect");

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->getScreen().width), static_cast<GLfloat>(this->getScreen().height), 0.0f, -1.0f, 1.0f);
	resMgr->getShader("sprite").setInteger("image", 0, GL_TRUE);
	resMgr->getShader("sprite").setMatrix4("projection", projection);
	
	this->spriteRenderer = new SpriteRenderer(resMgr->getShader("sprite"));
	this->effect = new PostProcessor(resMgr->getShader("effect"), this->getScreen().width, this->getScreen().height);
	this->textRenderer = new TextRenderer(this->getScreen().width, this->getScreen().height);
	this->textRenderer->load(CommonUtilities::getFullPath("examples/PostProcessing/OCRAEXT.TTF").c_str(), 24);

	this->gameImplementation->initLevel();
}

void Game::processInput(GLfloat dt) {
	if (this->keys[GLFW_KEY_ENTER] && !this->keysProcessed[GLFW_KEY_ENTER]) {
		this->keysProcessed[GLFW_KEY_ENTER] = GL_TRUE;
		this->effect->setEdgeDetection(!this->effect->getEdgeDetection());
	}
}

void Game::update(GLfloat dt) {

}

void Game::render() {
	this->effect->beginRender();

	/*this->spriteRenderer->draw(resMgr->getTexture("box"),
									glm::vec2(0, 0), 
									glm::vec2(this->getScreen().width, this->getScreen().height),
									0.0f);*/

	this->gameImplementation->renderLevel(spriteRenderer);
	
	this->effect->endRender();
	this->effect->postProcessRender(glfwGetTime());
	textRenderer->renderText("Press ENTER to toggle", 250.0f, this->getScreen().height / 2, 1.0f);
}


// Accessors
Screen Game::getScreen() {
	return this->screen;
}

GameState Game::getState() {
	return this->state;
}

GLboolean Game::getKeys(GLuint key) {
	return this->keys[key];
}

GLboolean Game::getKeysProcessed(GLuint key) {
	return this->keysProcessed[key];
}

// Mutators
void Game::setScreen(GLuint width, GLuint height) {
	this->screen = { width, height };
}

void Game::setState(GameState state) {
	this->state = state;
}

void Game::setKeys(GLuint key, GLboolean isPress) {
	this->keys[key] = isPress;
}

void Game::setKeysProcessed(GLuint key, GLboolean isPress) {
	this->keysProcessed[key] = isPress;
}

GameImpl* Game::gameImplementation;