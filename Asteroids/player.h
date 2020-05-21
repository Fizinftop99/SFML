#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
	bool flag{ false };

public:
	Player(Anim& a, float X, float Y, float Angle, int R);

	virtual ~Player() {};

	virtual void update();

	virtual bool getFlag();

    virtual void setFlag(bool b);

	virtual void setAnimation(Anim a);
    
	void setDx(float Dx);

    void setDy(float Dy);

	void setCoordinates(float X, float Y);

	void setNewState(float X, float Y, float Dx, float Dy, float Angle = 0, int R = 1);
};

