#include "Entity.h"

Entity::Entity() {
	isLife = true;
    /*anim = a;
    x = X; y = Y;
    angle = Angle;
    radius = R;   */
}
Entity::Entity(Anim& a, float X, float Y, std::string newName)
{
    isLife = true;
    x = X;
    y = Y;
    name = newName;
}
/*
void Entity::settings(Anim& a, float X, float Y, float Angle, int R) {
    anim = a;
    x = X; y = Y;
    angle = Angle;
    radius = R;
}
*/
void Entity::draw(RenderWindow& app) {
    anim.getSprite().setPosition(x, y);
    anim.getSprite().setRotation(angle + 90);
    app.draw(anim.getSprite());

    CircleShape circle(radius);
    circle.setFillColor(Color(255, 0, 0, 170));
    circle.setPosition(x, y);
    circle.setOrigin(radius, radius);
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

int Entity::getRadius()
{
    return radius;
}

void Entity::setRadius(int newRadius)
{
    radius = newRadius;
}

float Entity::getAngle()
{
    return angle;
}

void Entity::changeAngle(float angleChange)
{
    angle += angleChange;
}

std::string Entity::getName()
{
    return name;
}

void Entity::setName(std::string newName)
{
    name = newName;
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