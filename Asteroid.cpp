#include "Asteroid.h"
#include "constants.h"

Asteroid::Asteroid() {
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
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
