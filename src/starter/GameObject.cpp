#include "GameObject.h"

GameObject::GameObject() 
	: position(0, 0), size(1, 1), velocity(0.0f), color(1.0f), rotation(0.0f), sprite() {}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity)
	: position(pos), size(size), velocity(velocity), color(color), rotation(0.0f), sprite(sprite) {

}

// Accessors
glm::vec2 GameObject::getPosition() const {
	return this->position;
}

glm::vec2 GameObject::getSize() const {
	return this->size;
}

glm::vec2 GameObject::getVelocity() const {
	return this->velocity;
}

glm::vec3 GameObject::getColor() const {
	return this->color;
}

GLfloat GameObject::getRotation() const {
	return this->rotation;
}

Texture2D GameObject::getTexture() const {
	return this->sprite;
}

// Mutators
void GameObject::setPosition(glm::vec2 position) {
	this->position = position;
}

void GameObject::setSize(glm::vec2 size) {
	this->size = size;
}

void GameObject::setVelocity(glm::vec2 velocity) {
	this->velocity = velocity;
}

void GameObject::setColor(glm::vec3 color) {
	this->color = color;
}

void GameObject::setRotation(GLfloat rotation) {
	this->rotation = rotation;
}

void GameObject::setTexture(Texture2D sprite) {
	this->sprite = sprite;
}