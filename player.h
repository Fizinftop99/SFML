#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
	bool flag;

public:
	Player();

	virtual ~Player() {};

	virtual void update();

	virtual bool getFlag();

    virtual void setFlag(bool b);

    void setDx(float flag);

    void setDy(float flag);

	virtual void setAnimation(Anim a);
};

