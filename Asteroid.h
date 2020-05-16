#pragma once

#include "Entity.h"
#include <random>

class Asteroid : public Entity
{
public:
	Asteroid(Anim& a, float X, float Y, float Angle, int R);
	void update();

};

