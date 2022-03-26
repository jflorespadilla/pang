#pragma once
#include "VisibleGameObject.h"
#include <cassert>

class GameBall : public VisibleGameObject {
public:
    GameBall();
    virtual ~GameBall();
    void Update(float elapsedTime);

private:
    float _velocity;
    float _angle;
    float _elapsedTimeSinceStart;
    float _pi;

    float LinearVelocityX(float angle);
    float LinearVelocityY(float angle);
};

