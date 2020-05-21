#include "Animation.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Anim::Anim() {}

Anim::Anim(sf::Texture& t, int x0, int y0, int width, int height, int count, float Speed) {
        currentFrame = 0;
        speed = Speed;

        for (int i = 0; i < count; i++)
            frames.push_back(IntRect(x0 + i * width, y0, width, height));

        sprite.setTexture(t);
        sprite.setOrigin(width / 2, height / 2);
        sprite.setTextureRect(frames[0]);
    }

    void Anim::update()
    {
        currentFrame += speed;
        int n = frames.size();
        if (currentFrame >= n) currentFrame -= n;
        if (n > 0)
            sprite.setTextureRect(frames[static_cast <int> (currentFrame)]);
    }

    bool Anim::isEnd()
    {
        return currentFrame + speed >= frames.size();
    }

    Sprite& Anim::getSprite() {
        return sprite;
    }
 