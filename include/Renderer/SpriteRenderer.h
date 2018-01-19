#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Texture2D.h"
#include "Renderer2D.h"

class SpriteRenderer : public Renderer2D {
	public:
		SpriteRenderer(Shader &shader);
		~SpriteRenderer();

		void draw(Texture2D &texture, glm::vec2 position,
					glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
					glm::vec3 color = glm::vec3(1.0f));

	private:
		GLuint quadVAO;

		void init();
};

#endif // !SPRITE_RENDERER_H