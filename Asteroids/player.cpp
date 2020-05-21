#pragma once
#include "player.h"
#include "constants.h"
/*
Player::Player() {
	name = "player";
}
*/
Player::Player(Anim& a, float X, float Y, float Angle, int R)
{
    name = "player";

}

void Player::update()
{
    if (flag)
    {
        dx += cos(angle * DEGTORAD) * 0.2;
        dy += sin(angle * DEGTORAD) * 0.2;
    }
    else
    {
        dx *= 0.99;
        dy *= 0.99;
    }

    int maxSpeed = 15;

    float speed = sqrt(dx * dx + dy * dy);

    if (speed > maxSpeed)
    {
        dx *= maxSpeed / speed;
        dy *= maxSpeed / speed;
    }

    x += dx;
    y += dy;

    if (x > Constants::width)
        x = 0;
    if (x < 0)
        x = Constants::width;
    if (y > Constants::heigth)
        y = 0;
    if (y < 0)
        y = Constants::heigth;
}

bool Player::getFlag()
{
	return flag;
}

void Player::setFlag(bool b) 
{
    flag = b;
}

void Player::setDx(float Dx)
{
    dx = Dx;
}

void Player::setDy(float Dy)
{
    dy = Dy;
}

void Player::setCoordinates(float X, float Y)
{
    x = X;
    y = Y;
}
void Player::setNewState(float X, float Y, float Dx, float Dy, float Angle, int r)
{
    x = X;
    y = Y;
    dx = Dx;
    dy = Dy;
    angle = Angle;
    radius = r;
}

void Player::setAnimation(Anim a)
{
    anim = a;
}
