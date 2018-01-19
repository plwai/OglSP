#include "Renderer/FbRenderer.h"

#include <iostream>

FrameBufferRenderer::FrameBufferRenderer(GLuint width, GLuint height)
	: texture(), width(width), height(height){

	// Generate buffers id
	glGenFramebuffers(1, &this->MSFBO);
	glGenFramebuffers(1, &this->FBO);
	glGenRenderbuffers(1, &this->RBO);

	// Bind Render Buffer for Multisampling AA
	glBindFramebuffer(GL_FRAMEBUFFER, this->MSFBO);
	glBindRenderbuffer(GL_RENDERBUFFER, this->RBO);
	glRenderbufferStorageMultisample(GL_RENDERBUFFER, 8, GL_RGB, this->width, this->height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, this->RBO);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
		std::cout << "ERROR::FRAMEBUFFER_RENDERER: Failed to initialize MSFBO" << std::endl;
	}

	// Bind Texture for Final Quad Buffer
	glBindFramebuffer(GL_FRAMEBUFFER, this->FBO);
	this->texture.generate(width, height, NULL);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->texture.getTextureID(), 0);
	
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
		std::cout << "ERROR::FRAMEBUFFER_RENDERER: Fialed to initialize FBO" << std::endl;
	}

	// Clear Binding
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	this->init();
}

void FrameBufferRenderer::beginRender() {
	glBindFramebuffer(GL_FRAMEBUFFER, this->MSFBO);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void FrameBufferRenderer::endRender() {
	glBindFramebuffer(GL_READ_FRAMEBUFFER, this->MSFBO);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, this->FBO);
	glBlitFramebuffer(0, 0, this->width, this->height, 0, 0, this->width, this->height, GL_COLOR_BUFFER_BIT, GL_NEAREST);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

GLuint FrameBufferRenderer::getVAO() const {
	return this->VAO;
}

Texture2D FrameBufferRenderer::getFBTexture() const {
	return this->texture;
}

void FrameBufferRenderer::init() {
	GLuint VBO;
	GLfloat vertices[] = {
		-1.0f, -1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f,

		-1.0f, -1.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	};
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(this->VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}