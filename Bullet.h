#pragma once
#include "Entity.h"
#include "constants.h"
class Bullet : public Entity {
public:
    Bullet();

    virtual ~Bullet() {};

    void update();
};

