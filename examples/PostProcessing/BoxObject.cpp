#include "BoxObject.h"

BoxObject::BoxObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite) 
	: GameObject(pos, size, sprite) {

}

void BoxObject::draw(Renderer2D &renderer) {
	renderer.draw(sprite, position, size);
}