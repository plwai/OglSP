#include "GameImpl.h"

GameImpl::GameImpl(GLuint width, GLuint height)
	: screen({width, height}) {
}


GameImpl::~GameImpl() {

}

// Accessors
Screen GameImpl::getScreen() const{
	return this->screen;
}

// Mutators
void GameImpl::setScreen(GLuint width, GLuint height) {
	this->screen = { width, height };
}