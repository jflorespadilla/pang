#pragma once
#include "VisibleGameObject.h"

class GameObjectManager {
public:
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, VisibleGameObject* gameObject);
	void Remove(std::string name);
	int GameObjectCount() const;
	VisibleGameObject* Get(std::string name) const;
	VisibleGameObject* paddle1;
	VisibleGameObject* paddle2;
	VisibleGameObject* ball;

	void DrawAll(sf::RenderWindow& renderWindow);
	void UpdateAll();

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;
	struct GameObjectDeallocator {
		void operator() (const std::pair<std::string, VisibleGameObject*>& p) const {
			delete p.second;
		}
	};
};

