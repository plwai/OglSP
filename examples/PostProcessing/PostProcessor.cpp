#include "PostProcessor.h"

PostProcessor::PostProcessor(Shader &shader, GLuint width, GLuint height) 
	: postProcessShader(shader), FrameBufferRenderer(width, height), edgeDetection(GL_FALSE) {

	this->postProcessShader.setInteger("scene", 0, GL_TRUE);

	GLfloat offset = 1.0f / 300.0f;
	GLfloat offsets[9][2] = {
		{ -offset, offset },  // top-left
	{ 0.0f, offset },  // top-center
	{ offset, offset },  // top-right
	{ -offset, 0.0f },  // center-left
	{ 0.0f, 0.0f },  // center-center
	{ offset, 0.0f },  // center - right
	{ -offset, -offset },  // bottom-left
	{ 0.0f, -offset },  // bottom-center
	{ offset, -offset }   // bottom-right    
	};
	glUniform2fv(glGetUniformLocation(this->postProcessShader.getShaderID(), "offsets"), 9, (GLfloat*)offsets);

	GLfloat edge_kernel[9] = {
		-1, -1, -1,
		-1, 8, -1,
		-1, -1, -1,
	};
	glUniform1fv(glGetUniformLocation(this->postProcessShader.getShaderID(), "edge_kernel"), 9, edge_kernel);
}

void PostProcessor::postProcessRender(GLfloat time) {
	this->postProcessShader.use();
	this->postProcessShader.setInteger("edge", this->edgeDetection);

	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(FrameBufferRenderer::getVAO());
	FrameBufferRenderer::getFBTexture().bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

// Accessors
Shader PostProcessor::getPostProcessShader() const {
	return this->postProcessShader;
}

GLboolean PostProcessor::getEdgeDetection() const {
	return this->edgeDetection;
}

// Mutators
void PostProcessor::setPostProcessShader(Shader &shader) {
	this->postProcessShader = shader;
}

void PostProcessor::setEdgeDetection(GLboolean edgeDetection) {
	this->edgeDetection = edgeDetection;
}