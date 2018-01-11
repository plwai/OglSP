#ifndef BOX_OBJECT_H
#define BOX_OBJECT_H

#include <GameObject.h>
#include "Audio.h"
#include "AudioEngine.h"

class BoxObject : public GameObject {
	public:
		BoxObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite);
		BoxObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, Audio audio);
		void draw(Renderer2D &renderer);

		void playAudio(AudioEngine* audioEngine);

	private:
		Audio audio;
};

#endif // !BOX_OBJECT_H

