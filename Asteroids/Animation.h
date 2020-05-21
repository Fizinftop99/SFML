#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Anim {
private:
    float currentFrame;
    float speed;
    Sprite sprite;
    std::vector<IntRect> frames;

public:
    Anim();

    Anim(Texture& t, int x0, int y0, int width, int height, int count, float Speed);

    void update();

    bool isEnd();

    Sprite& getSprite();
};
