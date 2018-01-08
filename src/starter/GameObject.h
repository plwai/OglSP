#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Texture2D.h"
#include "Renderer2D.h"

class GameObject {
	public:
		virtual void draw(Renderer2D &renderer) = 0;

		GameObject();
		GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));

		// Accessors
		glm::vec2 getPosition() const;
		glm::vec2 getSize() const;
		glm::vec2 getVelocity() const;
		glm::vec3 getColor() const;
		GLfloat getRotation() const;
		Texture2D getTexture() const;

		// Mutators
		void setPosition(glm::vec2 position);
		void setSize(glm::vec2 size);
		void setVelocity(glm::vec2 velocity);
		void setColor(glm::vec3 color);
		void setRotation(GLfloat rotation);
		void setTexture(Texture2D sprite);

	protected:
		glm::vec2 position, size, velocity;
		glm::vec3 color;
		GLfloat rotation;
		
		Texture2D sprite;
};

#endif // !GAME_OBJECT_H
