#pragma once
#include <string>
#include<SFML/Graphics.hpp>

class VisibleGameObject {
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow& renderWindow);

	virtual void SetPosition(float x, float y);

private:
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;

};

