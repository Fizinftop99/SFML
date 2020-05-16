#include "Asteroid.h"
#include "constants.h"

/*Asteroid::Asteroid(Anim& a, float X, float Y, float Angle, int R) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-4, 4);
    dx = static_cast<float>(dis(gen));
    dy = static_cast<float>(dis(gen));
    name = "asteroid";
}*/

Asteroid::Asteroid(Anim& a, float X, float Y, float Angle, int R)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-4, 4);
    dx = static_cast<float>(dis(gen));
    dy = static_cast<float>(dis(gen));
    name = "asteroid";
}

void Asteroid::update()
{
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
