#include "Game.h"

#include <iostream>

#include "ResourceManager.h"
#include "CommonUtilities.h"
#include "SpriteRenderer.h"
#include "PostProcessor.h"

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

}

void Game::processInput(GLfloat dt) {

}

void Game::update(GLfloat dt) {

}

void Game::render() {

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