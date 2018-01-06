#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Texture2D.h"

class SpriteRenderer {
	public:
		SpriteRenderer(Shader &shader);
		~SpriteRenderer();

		void drawSprite(Texture2D &texture, glm::vec2 position,
						glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
						glm::vec3 color = glm::vec3(1.0f));

		// Acessors
		Shader getCurrentShader() const;

		// Mutators
		void setShader(Shader &shader);

	private:
		Shader shader;
		GLuint quadVAO;

		void init();
};

#endif // !SPRITE_RENDERER_H