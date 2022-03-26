#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject() : _isLoaded(false) {
	
}

VisibleGameObject::~VisibleGameObject() {

}

void VisibleGameObject::Load(std::string filename) {
	if (_image.loadFromFile(filename) == false) {
		_filename = "";
		_isLoaded = false;
	}
	else {
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow& renderWindow) {
	if (_isLoaded) {
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::Update(float elapsedTime) {

}

void VisibleGameObject::SetPosition(float x, float y) {
	if (_isLoaded) {
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::GetPosition() const {
	if (_isLoaded) {
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

float VisibleGameObject::GetWidth() const {
	return _sprite.getScale().x;
}

float VisibleGameObject::GetHeight() const {
	return _sprite.getScale().y;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const {
	sf::Vector2f size = _sprite.getScale();
	sf::Vector2f position = _sprite.getPosition();

	return sf::Rect<float>(position.x - size.x / 2,
		                               position.y - size.y / 2,
		                               position.x + size.x / 2,
		                               position.y + size.y / 2);
}

sf::Sprite& VisibleGameObject::GetSprite() {
	return _sprite;
}

bool VisibleGameObject::IsLoaded() const {
	return _isLoaded;
}