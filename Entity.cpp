#include "Entity.h"

Entity::Entity() {
	isLife = true;
}

void Entity::settings(Anim& a, int X, int Y, float Angle, int R) {
    anim = a;
    x = X; y = Y;
    angle = Angle;
    radius = R;
}

void Entity::draw(RenderWindow& app) {
    anim.getSprite().setPosition(x, y);
    anim.getSprite().setRotation(angle + 90);
    app.draw(anim.getSprite());

    CircleShape circle(radius);
    circle.setFillColor(Color(255, 0, 0, 170));
    circle.setPosition(x, y);
    circle.setOrigin(radius, radius);
    app.draw(circle);
}

float Entity::getX()
{
    return 0.0f;
}

float Entity::getY()
{
    return 0.0f;
}

int Entity::getRadius()
{
    return 0;
}

void Entity::setRadius(int r)
{
}

float Entity::getAngle()
{
    return 0.0f;
}

void Entity::changeAngle(float angleChange)
{
    angle += angleChange;
}

std::string Entity::getName()
{
    return name;
}

void Entity::setName(std::string n)
{
    name = n;
}

bool Entity::getIsLife()
{
    return isLife;
}

void Entity::setIsLife(bool b)
{
    isLife = b;
}

Anim& Entity::getAnim()
{
    return anim;
}


