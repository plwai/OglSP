#include "Renderer2D.h"

Renderer2D::Renderer2D() {

}

Renderer2D::~Renderer2D() {

}

// Accessors
Shader Renderer2D::getCurrentShader() const {
	return this->shader;
}

// Mutators
void Renderer2D::setShader(Shader &shader) {
	this->shader = shader;
}