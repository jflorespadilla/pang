#pragma once
#include "VisibleGameObject.h"
#include "Game.h"
#include <cassert>

class PlayerPaddle : public VisibleGameObject {
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& renderWindow);

	float GetVelocity() const;

private:
	float _velocity;
	float _maxVelocity;
};

