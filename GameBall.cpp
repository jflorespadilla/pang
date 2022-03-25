#include "GameBall.h"

GameBall::GameBall() {
	Load("ball.png");
	assert(IsLoaded());
	GetSprite().setOrigin(15, 15);
}

GameBall::~GameBall() {

}