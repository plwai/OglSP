#include <iostream>

#include "Texture2D.h"

Texture2D::Texture2D()
	: width(0), height(0), internalFormat(GL_RGB), imageFormat(GL_RGB), wrapS(GL_REPEAT), wrapT(GL_REPEAT), filterMin(GL_LINEAR), filterMax(GL_LINEAR)
{
	glGenTextures(1, &this->ID);
}

void Texture2D::generate(GLuint width, GLuint height, unsigned char* data) {
	this->setWidth(width);
	this->setHeight(height);

	// Set texture config
	glBindTexture(GL_TEXTURE_2D, this->getTextureID());
	glTexImage2D(GL_TEXTURE_2D, 0, this->getInternalFormat(), width, height, 0, this->getImageFormat(), GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->getWrapS());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->getWrapT());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->getFilterMin());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->getFilterMax());

	// Free texture binding
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::bind() const {
	glBindTexture(GL_TEXTURE_2D, this->getTextureID());
}

// Accessors
GLuint Texture2D::getTextureID() const {
	return this->ID;
}

GLuint Texture2D::getWidth() const {
	return this->width;
}

GLuint Texture2D::getHeight() const {
	return this->height;
}

GLuint Texture2D::getInternalFormat() const {
	return this->internalFormat;
}

GLuint Texture2D::getImageFormat() const {
	return this->imageFormat;
}

GLuint Texture2D::getWrapS() const {
	return this->wrapS;
}

GLuint Texture2D::getWrapT() const {
	return this->wrapT;
}

GLuint Texture2D::getFilterMin() const {
	return this->filterMin;
}

GLuint Texture2D::getFilterMax() const {
	return this->filterMax;
}

// Mutators
void Texture2D::setWidth(GLuint width) {
	this->width = width;
}

void Texture2D::setHeight(GLuint height) {
	this->height = height;
}

void Texture2D::setInternalFormat(GLuint internalFormat) {
	this->internalFormat = internalFormat;
}

void Texture2D::setImageFormat(GLuint imageFormat) {
	this->imageFormat = imageFormat;
}

void Texture2D::setWrapS(GLuint wrapS) {
	this->wrapS = wrapS;
}

void Texture2D::setWrapT(GLuint wrapT) {
	this->wrapT = wrapT;
}

void Texture2D::setFilterMin(GLuint filterMin) {
	this->filterMin = filterMin;
}

void Texture2D::setFilterMax(GLuint filterMax) {
	this->filterMax = filterMax;
}

void Texture2D::setTextureID(GLuint ID) {
	this->ID = ID;
}