#include "PixelObject.h"

PixelObject::PixelObject(GFXdata &gfx, glm::vec2 size, glm::vec2 position, glm::vec3 color) 
	: texture(), gfx(gfx), size(size), position(position), color(color) {

	this->init();
}

PixelObject::PixelObject(glm::vec2 size, glm::vec2 position, glm::vec3 color)
	: texture(), gfx({0,0,0}), size(size), position(position), color(color) {

	this->init();
}

PixelObject::~PixelObject() {

}

void PixelObject::draw(Renderer2D &renderer) {
	renderer.draw(this->texture, this->getPosition(), this->size, 0.0f, this->color);
}

void PixelObject::update(GFXdata &gfx) {
	this->gfx = gfx;
	this->texture.bind();

	this->texture.update(this->gfx.width, this->gfx.height, this->gfx.gfx);
}

// Accessors
glm::vec2 PixelObject::getPosition() const {
	return this->position;
}

glm::vec2 PixelObject::getSize() const {
	return this->size;
}

glm::vec3 PixelObject::getColor() const {
	return this->color;
}

// Mutators
void PixelObject::setPosition(glm::vec2 position) {
	this->position = position;
}

void PixelObject::setSize(glm::vec2 size) {
	this->size = size;
}

void PixelObject::setColor(glm::vec3 color) {
	this->color = color;
}

void PixelObject::init() {
	this->texture.setFilterMax(GL_NEAREST);
	this->texture.setFilterMax(GL_NEAREST);
	this->texture.setWrapS(GL_CLAMP_TO_BORDER);
	this->texture.setWrapT(GL_CLAMP_TO_BORDER);

	this->texture.generate(this->size.x, this->size.y, NULL);
	this->texture.update(this->gfx.width, this->gfx.height, this->gfx.gfx);
}