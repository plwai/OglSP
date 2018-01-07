#include "Game.h"

#include <iostream>

#include <ResourceManager.h>
#include <CommonUtilities.h>
#include <SpriteRenderer.h>
#include "PostProcessor.h"
#include <iostream>

Game::Game(GLuint width, GLuint height) {
	if (gameImplementation == nullptr) {
		gameImplementation = new GameImpl(width, height);
	}

	resMgr = ResourceManager::GetInstance();
}

Game::~Game() {
	delete gameImplementation;
}

void Game::init() {
	resMgr->loadShader(CommonUtilities::getFullPath("src/shaders/sprite.vert").c_str(), CommonUtilities::getFullPath("src/shaders/sprite.frag").c_str(), nullptr, "sprite");
	resMgr->loadShader(CommonUtilities::getFullPath("examples/PostProcessing/postProcess.vert").c_str(), CommonUtilities::getFullPath("examples/PostProcessing/postProcess.frag").c_str(), nullptr, "effect");

	resMgr->loadTexture(CommonUtilities::getFullPath("examples/PostProcessing/box_texture.jpg").c_str(), GL_FALSE, "box");

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->getScreen().width), static_cast<GLfloat>(this->getScreen().height), 0.0f, -1.0f, 1.0f);
	resMgr->getShader("sprite").setInteger("image", 0, GL_TRUE);
	resMgr->getShader("sprite").setMatrix4("projection", projection);
	
	this->gameImplementation->setSpriteRenderer(new SpriteRenderer(resMgr->getShader("sprite")));
	this->gameImplementation->setPostProcessor(resMgr->getShader("effect"));
}

void Game::processInput(GLfloat dt) {
	if (this->keys[GLFW_KEY_ENTER] && !this->keysProcessed[GLFW_KEY_ENTER]) {
		this->keysProcessed[GLFW_KEY_ENTER] = GL_TRUE;
		this->gameImplementation->getPostProcessor()->setEdgeDetection(!this->gameImplementation->getPostProcessor()->getEdgeDetection());
	}
}

void Game::update(GLfloat dt) {

}

void Game::render() {
	this->gameImplementation->getPostProcessor()->beginRender();

	this->gameImplementation->getSpriteRenderer()->drawSprite(resMgr->getTexture("box"),
															  glm::vec2(0, 0), 
															  glm::vec2(this->gameImplementation->getScreen().width, this->gameImplementation->getScreen().height),
															  0.0f);

	this->gameImplementation->getPostProcessor()->endRender();
	this->gameImplementation->getPostProcessor()->postProcessRender(glfwGetTime());
}


// Accessors
Screen Game::getScreen() {
	return this->gameImplementation->getScreen();
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
	this->gameImplementation->setScreen(width, height);
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