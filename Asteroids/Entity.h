#pragma once
#include "Animation.h"

class Entity {
protected:
    int radius;
    const float DEGTORAD = 0.017453f;
    float x, y, dx, dy, angle;
    std::string name;
    bool isLife;
    Anim anim;

public:
    Entity();
    Entity(Anim& a, float X, float Y, std::string newName);

    virtual ~Entity() {};

    virtual void update() {};

    virtual bool getFlag() { return false; }; // function for class Player

    virtual void setFlag() {}; // function for class Player

    virtual void setAnimation() {}; // function for class Player

    //virtual void setC

    //void settings(Anim& a, float X, float Y, float Angle = 0, int R = 1);

    void draw(RenderWindow& app);

    float getX();

    float getY();

    int getRadius();

    void setRadius(int r);

    float getAngle();

    void changeAngle(float flag);

    std::string getName();

    void setName(std::string n);

    bool getIsLife();

    void setIsLife(bool b);

    Anim& getAnim();
};
