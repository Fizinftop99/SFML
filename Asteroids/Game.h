#pragma once
#include <memory>
#include "Entity.h"
class Game {
public:
	void start();

	bool isCollide(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);
};

