#include "BoxObject.h"

BoxObject::BoxObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite) 
	: GameObject(pos, size, sprite), audio(NULL) {

}

BoxObject::BoxObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, Audio audio) 
	: GameObject(pos, size, sprite), audio(audio) {

}

void BoxObject::draw(Renderer2D &renderer) {
	renderer.draw(sprite, position, size);
}

void BoxObject::playAudio(AudioEngine* audioEngine) {
	audioEngine->play(&this->audio);
}