#include "GameImpl.h"

GameImpl::GameImpl() {
	resMgr = ResourceManager::GetInstance();
}


GameImpl::~GameImpl() {
}

void GameImpl::initLevel() {
	resMgr->loadTexture(CommonUtilities::getFullPath("examples/PostProcessing/box_texture.jpg").c_str(), GL_FALSE, "box");
	boxesCollection.push_back(new BoxObject(glm::vec2(10, 10), glm::vec2(250, 250), resMgr->getTexture("box")));
	boxesCollection.push_back(new BoxObject(glm::vec2(270, 10), glm::vec2(250, 250), resMgr->getTexture("box")));
	boxesCollection.push_back(new BoxObject(glm::vec2(530, 10), glm::vec2(250, 250), resMgr->getTexture("box")));

	boxesCollection.push_back(new BoxObject(glm::vec2(10, 340), glm::vec2(250, 250), resMgr->getTexture("box")));
	boxesCollection.push_back(new BoxObject(glm::vec2(270, 340), glm::vec2(250, 250), resMgr->getTexture("box")));
	boxesCollection.push_back(new BoxObject(glm::vec2(530, 340), glm::vec2(250, 250), resMgr->getTexture("box")));
}

void GameImpl::renderLevel(Renderer2D* renderer) {
	for (auto box : this->boxesCollection) {
		box->draw(*renderer);
	}
}

std::vector<BoxObject*> GameImpl::getBoxCollection() const {
	return this->boxesCollection;
}

void GameImpl::setBoxCollection(std::vector<BoxObject*> boxesCollection) {
	this->boxesCollection = boxesCollection;
}