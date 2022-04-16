#include "AIPaddle.h"
#include "Game.h"
#include "GameBall.h"

AIPaddle::AIPaddle() :
	_velocity(0),
	_maxVelocity(600.0f)
{
	Load("paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
}

AIPaddle::~AIPaddle() {

}

void AIPaddle::Draw(sf::RenderWindow& renderWindow) {
	VisibleGameObject::Draw(renderWindow);
}

float AIPaddle::GetVelocity() const {
	return _velocity;
}

void AIPaddle::Update(float elapsedTime) {
	const GameBall* gameBall= static_cast<GameBall*>(Game::GetGameObjectManager().paddle2);
	sf::Vector2f ballPosition = gameBall->GetPosition();

	if (GetPosition().x - 20 < ballPosition.x) {
		_velocity += 15.0f;
	}
	else if (GetPosition().x + 20 > ballPosition.x) {
		_velocity -= 10.0f;
	}
	else {
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity) {
		_velocity = _maxVelocity;
	}
	if (_velocity < -_maxVelocity) {
		_velocity = -_maxVelocity;
	}

	sf::Vector2f pos = this->GetPosition();
	if (pos.x < GetSprite().getScale().x / 2
		|| pos.x >= (Game::SCREEN_WIDTH - GetSprite().getScale().x / 2))
	{
		_velocity = -_velocity;
	}
	GetSprite().move(_velocity * elapsedTime, 0);
}