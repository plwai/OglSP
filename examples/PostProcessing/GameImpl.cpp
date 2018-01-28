#include "GameImpl.h"

GameImpl::GameImpl() {
	resMgr = ResourceManager::GetInstance();
}


GameImpl::~GameImpl() {
}

void GameImpl::initLevel() {
	resMgr->loadTexture(CommonUtilities::getFullPath("resource/textures/box_texture.jpg").c_str(), GL_FALSE, "box");
	boxesCollection.push_back(new BoxObject(glm::vec2(10, 10), glm::vec2(250, 250), resMgr->getTexture("box"), AudioEngine::GetInstance()->getAudio("sample")));
	boxesCollection.push_back(new BoxObject(glm::vec2(270, 10), glm::vec2(250, 250), resMgr->getTexture("box")));
	boxesCollection.push_back(new BoxObject(glm::vec2(530, 10), glm::vec2(250, 250), resMgr->getTexture("box")));

	boxesCollection.push_back(new BoxObject(glm::vec2(10, 340), glm::vec2(250, 250), resMgr->getTexture("box")));
	boxesCollection.push_back(new BoxObject(glm::vec2(270, 340), glm::vec2(250, 250), resMgr->getTexture("box")));
	boxesCollection.push_back(new BoxObject(glm::vec2(530, 340), glm::vec2(250, 250), resMgr->getTexture("box")));

	unsigned char pixelData[100*100*3];
	
	for (int i = 0; i < 100 * 100 * 3; i++) {
		pixelData[i] = 255;
	}

	GFXdata gfx = {pixelData, 100, 100};
	pixelObjCollection.push_back(new PixelObject(glm::vec2(100), glm::vec2(85, 85), glm::vec3(255, 0, 0)));
	pixelObjCollection.front()->update(gfx);
	pixelObjCollection.push_back(new PixelObject(gfx, glm::vec2(100), glm::vec2(345, 85), glm::vec3(0, 255, 0)));
	pixelObjCollection.push_back(new PixelObject(gfx, glm::vec2(100), glm::vec2(605, 85), glm::vec3(0, 0, 255)));

	pixelObjCollection.push_back(new PixelObject(gfx, glm::vec2(100), glm::vec2(85, 415), glm::vec3(255, 0, 255)));
	pixelObjCollection.push_back(new PixelObject(gfx, glm::vec2(100), glm::vec2(345, 415), glm::vec3(255, 255, 0)));
	pixelObjCollection.push_back(new PixelObject(gfx, glm::vec2(100), glm::vec2(605, 415), glm::vec3(0, 255, 255)));

	boxesCollection.front()->playAudio(AudioEngine::GetInstance());
}

void GameImpl::renderLevel(Renderer2D* renderer) {
	for (auto box : this->boxesCollection) {
		box->draw(*renderer);
	}

	for (auto pixel : this->pixelObjCollection) {
		pixel->draw(*renderer);
	}
}

std::vector<BoxObject*> GameImpl::getBoxCollection() const {
	return this->boxesCollection;
}

void GameImpl::setBoxCollection(std::vector<BoxObject*> boxesCollection) {
	this->boxesCollection = boxesCollection;
}