#include "GameObjectManager.h"
#include "Game.h"

GameObjectManager::GameObjectManager() {

}

GameObjectManager::~GameObjectManager() {
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject) {
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name) {
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end()) {
		delete results->second;
		_gameObjects.erase(results);
	}
}

VisibleGameObject* GameObjectManager::Get(std::string name) const {
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end()) {
		return NULL;
	}
	return results->second;
}

int GameObjectManager::GameObjectCount() const {
	return _gameObjects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow) {
	/*std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end()) {
		itr->second->Draw(renderWindow);
		itr++;
	}*/
	ball->Draw(renderWindow);
	paddle1->Draw(renderWindow);
	paddle2->Draw(renderWindow);
}

void GameObjectManager::UpdateAll() {
	//std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	float timeDelta = Game::GetElapsedTime().asSeconds();

	ball->Update(timeDelta);
	paddle1->Update(timeDelta);
	paddle2->Update(timeDelta);

	/*while (itr != _gameObjects.end()) {
		itr->second->Update(timeDelta);
		itr++;
	}*/
}
