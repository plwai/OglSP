#ifndef BOX_OBJECT_H
#define BOX_OBJECT_H

#include <GameObject.h>

class BoxObject : public GameObject {
	public:
		BoxObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite);
		void draw(Renderer2D &renderer);
};

#endif // !BOX_OBJECT_H

