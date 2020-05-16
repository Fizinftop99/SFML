#include "Game.h"
#include "Animation.h"
#include "player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "constants.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <random>
#include <algorithm>
//#include <iostream>

using namespace sf;

bool Game::isCollide(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
{
	return (b->getX() - a->getX()) * (b->getX() - a->getX()) +
		(b->getY() - a->getY()) * (b->getY() - a->getY()) <
		(a->getRadius() + b->getRadius()) * (a->getRadius() + b->getRadius());
}

void Game::start()
{
	//srand(time(0));
	std::random_device rd;
	std::mt19937 gen(rd());
	int m = std::max(Constants::heigth, Constants::width);
	std::uniform_int_distribution<> dis(0, m);

	RenderWindow app(VideoMode(Constants::width, Constants::heigth), "Asteroids!");
	app.setFramerateLimit(60);

	Texture t1, t2, t3, t4, t5, t6, t7;
	t1.loadFromFile("images/spaceship.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/explosions/type_C.png");
	t4.loadFromFile("images/rock.png");
	t5.loadFromFile("images/fire_blue.png");
	t6.loadFromFile("images/rock_small.png");
	t7.loadFromFile("images/explosions/type_B.png");

	t1.setSmooth(true);
	t2.setSmooth(true);

	Sprite background(t2);

	Anim sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
	Anim sRock(t4, 0, 0, 64, 64, 16, static_cast<float>(0.2));
	Anim sRock_small(t6, 0, 0, 64, 64, 16, static_cast<float>(0.2));
	Anim sBullet(t5, 0, 0, 32, 64, 16, static_cast<float>(0.8));
	Anim sPlayer(t1, 40, 0, 40, 40, 1, 0);
	Anim sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
	Anim sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);

	std::list<std::shared_ptr<Entity>> entities;

	for (int i = 0; i < 15; i++)
	{
		std::shared_ptr<Entity> a(new Asteroid());
		a->settings(sRock, static_cast<float>(dis(gen) % Constants::width), static_cast<float>(dis(gen) % Constants::heigth), static_cast<float>(dis(gen) % 360), 25);
		entities.push_back(a);
	}

	std::shared_ptr<Player> p(new Player());
	p->settings(sPlayer, 200, 200, 0, 20);
	entities.push_back(p);

	/////main loop/////
	while (app.isOpen())
	{
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();

			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
				{
					std::shared_ptr<Entity> b(new Bullet());
					b->settings(sBullet, p->getX(), p->getY(), p->getAngle(), 10);
					entities.push_back(b);
					
				}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) p->changeAngle(3);
		if (Keyboard::isKeyPressed(Keyboard::Left))  p->changeAngle(-3);
		if (Keyboard::isKeyPressed(Keyboard::Up)) p->setFlag(true);
		else p->setFlag(false);

		for (auto a : entities)
			for (auto b : entities)
			{

				//    /*
				if (a->getName() == "asteroid" && b->getName() == "bullet")
					if (isCollide(a, b))
					{
						a->setIsLife(false);
						b->setIsLife(false);

						std::shared_ptr<Entity> e(new Entity());
						e->settings(sExplosion, a->getX(), a->getY());
						e->setName("explosion");
						entities.push_back(e);


						for (int i = 0; i < 2; i++)
						{
							if (a->getRadius() == 15) continue;
							std::shared_ptr<Entity> e(new Asteroid());
							e->settings(sRock_small, a->getX(), a->getY(), static_cast<float>(dis(gen) % 360), 15);
							entities.push_back(e);
						}

						
					}

				if (a->getName() == "player" && b->getName() == "asteroid")
					if (isCollide(a, b))
					{
						
						b->setIsLife(false);

						std::shared_ptr<Entity> e(new Entity());
						e->settings(sExplosion_ship, a->getX(), a->getY());
						e->setName("explosion");
						entities.push_back(e);

						p->settings(sPlayer, Constants::width / 2, Constants::heigth / 2, 0, 20);
						p->setDx(0);
						
						p->setDy(0);
						
					}
			}
		//           */
		if (p->getFlag())  p->setAnimation(sPlayer_go);
		else   p->setAnimation(sPlayer);


		for (auto e : entities)
			if (e->getName() == "explosion")
				if (e->getAnim().isEnd()) e->setIsLife(false);

		if (dis(gen) % 150 == 0)
		{
			std::shared_ptr<Entity> a(new Asteroid());
			a->settings(sRock, 0, static_cast<float>(dis(gen) % Constants::heigth), static_cast<float>(dis(gen) % 360), 25);
			entities.push_back(a);
		}

		for (auto i = entities.begin(); i != entities.end();)
		{
			i->get()->update();
			i->get()->getAnim().update();

			if (i->get()->getIsLife() == false)
			{
				i = entities.erase(i);
			}
			else i++;
		}

		// drawing
		app.draw(background);
		for (auto&& i : entities) i->draw(app);
		app.display();
	}

}
