#ifndef RENDERER_2D_H
#define RENDERER_2D_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Texture2D.h"
#include "Shader.h"

class Renderer2D {
	public:
		Renderer2D();
		~Renderer2D();
		virtual void draw(Texture2D &texture, glm::vec2 position,
						  glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
						  glm::vec3 color = glm::vec3(1.0f)) = 0;

		// Acessors
		Shader getCurrentShader() const;

		// Mutators
		void setShader(Shader &shader);

	private:
		Shader shader;
};

#endif // !RENDERER_2D_H

