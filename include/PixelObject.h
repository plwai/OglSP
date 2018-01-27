#ifndef PIXEL_OBJECT_H
#define PIXEL_OBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Renderer/Renderer2D.h"
#include "Renderer/Texture2D.h"

struct GFXdata {
	unsigned char* gfx;
	GLuint width;
	GLuint height;
};

class PixelObject {
	public:
		PixelObject(GFXdata &gfx, glm::vec2 size, glm::vec2 position = glm::vec2(0.0f), glm::vec3 color = glm::vec3(1.0f));
		~PixelObject();

		void draw(Renderer2D &renderer);
		void update(GFXdata &gfx);

		// Accessors
		glm::vec2 getPosition() const;
		glm::vec2 getSize() const;
		glm::vec3 getColor() const;

		// Mutators
		void setPosition(glm::vec2 position);
		void setSize(glm::vec2 size);
		void setColor(glm::vec3 color);

	private:
		Texture2D texture;
		glm::vec2 size;
		glm::vec2 position;
		glm::vec3 color;
		GFXdata gfx;

		void init();
};

#endif // !PIXEL_OBJECT_H
