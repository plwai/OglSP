#include "GameImpl.h"

GameImpl::GameImpl(GLuint width, GLuint height)
	: screen({width, height}) {
}


GameImpl::~GameImpl() {
	delete this->spriteRenderer;
}

// Accessors
Screen GameImpl::getScreen() const{
	return this->screen;
}

SpriteRenderer* GameImpl::getSpriteRenderer() const {
	return this->spriteRenderer;
}

PostProcessor* GameImpl::getPostProcessor() const {
	return this->effect;
}

// Mutators
void GameImpl::setScreen(GLuint width, GLuint height) {
	this->screen = { width, height };
}

void GameImpl::setSpriteRenderer(SpriteRenderer* renderer) {
	this->spriteRenderer = renderer;
}

void GameImpl::setPostProcessor(PostProcessor* effect) {
	this->effect = effect;
}

void GameImpl::setPostProcessor(Shader &shader) {
	this->effect = new PostProcessor(shader, this->screen.width, this->screen.height);
}