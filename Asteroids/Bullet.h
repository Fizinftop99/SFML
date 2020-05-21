#pragma once
#include "Entity.h"
#include "constants.h"
class Bullet : public Entity {
public:
    Bullet(Anim& a, float X, float Y, float Angle, int R);

    virtual ~Bullet() {};

    void update();
};

