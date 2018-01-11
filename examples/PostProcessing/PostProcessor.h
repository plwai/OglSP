#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <Renderer/FbRenderer.h>
#include <Renderer/Shader.h>

class PostProcessor : public FrameBufferRenderer {
	public:
		PostProcessor() {}
		PostProcessor(Shader &shader, GLuint width, GLuint height);

		void postProcessRender(GLfloat time);

		// Accessors
		Shader getPostProcessShader() const;
		GLboolean getEdgeDetection() const;

		// Mutators
		void setPostProcessShader(Shader &shader);
		void setEdgeDetection(GLboolean edgeDetection);

	private:
		GLboolean edgeDetection;

		Shader postProcessShader;
};

#endif // !POST_PROCESSOR_H
