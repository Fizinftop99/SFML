#include "Bullet.h"

Bullet::Bullet(Anim& a, float X, float Y, float Angle, int R)
{

    name = "bullet";
}

void Bullet::update() {
    dx = cos(angle * DEGTORAD) * 6;
    dy = sin(angle * DEGTORAD) * 6;
    // angle+=rand()%7-3;  /*try this*/
    x += dx;
    y += dy;

    if (x > Constants::width || x < 0 || y > Constants::heigth || y < 0) isLife = 0;
}
