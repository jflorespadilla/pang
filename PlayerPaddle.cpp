#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle() :
	_velocity(0),
	_maxVelocity(600.0f)
{
	Load("paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
}

PlayerPaddle::~PlayerPaddle() {

}

void PlayerPaddle::Draw(sf::RenderWindow& renderWindow) {
	VisibleGameObject::Draw(renderWindow);
}

float PlayerPaddle::GetVelocity() const {
	return _velocity;
}

void PlayerPaddle::Update(float elapsedTime) {
	if (Game::GetInput().IsKeyDown(sf::Keyboard::Left)) {
		_velocity -= 3.0f;
	}
	if (Game::GetInput().IsKeyDown(sf::Keyboard::Right)) {
		_velocity += 3.0f;
	}
	if (Game::GetInput().IsKeyDown(sf::Keyboard::Down)) {
		_velocity -= 0.0f;
	}

	if (_velocity > _maxVelocity) {
	_velocity = _maxVelocity;
	}
	if (_velocity  < -_maxVelocity) {
		_velocity = -_maxVelocity;
	}

	sf::Vector2f pos = this->GetPosition();
	if (pos.x < GetSprite().getScale().x/2
		|| pos.x > (Game::SCREEN_WIDTH - GetSprite().getScale()/2))
	{
		_velocity - _velocity;
	}
	GetSprite().move(_velocity * elapsedTime, 0);
}