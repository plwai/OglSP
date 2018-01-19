#ifndef FB_RENDERER
#define FB_RENDERER

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Texture2D.h"

class FrameBufferRenderer {
	public:
		FrameBufferRenderer() {}
		FrameBufferRenderer(GLuint width, GLuint height);
		
		virtual void postProcessRender(GLfloat time) = 0;

		void beginRender();
		void endRender();

	protected:
		// Accessors
		GLuint getVAO() const;
		Texture2D getFBTexture() const;

	private:
		GLuint MSFBO, FBO;
		GLuint RBO;
		GLuint VAO;
		GLuint width, height;

		Texture2D texture;

		void init();
};

#endif // !FB_RENDERER
