#include <iostream>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>

class Molecula {
public:
	Molecula(const Molecula&) = default;

	Molecula(const float w, const float h) : 
		r{ 2.0f },
		x{ gen_from_to(10, w - 10) }, 
		y{ gen_from_to(10, h - 10) },
		gen{ rd() }
	{}

	void draw(sf::RenderWindow& window) {
		sf::CircleShape circle(2.0f * r);
		circle.setPosition(x, y);
		circle.setFillColor(sf::Color::Red);

		window.draw(circle);
	}

	float gen_from_to(float a, float b) {
		std::uniform_real_distribution<float> dis(a, b);

		return dis(gen);
	}

	void move(const float w, const float h) {
		if (x > w) x = 0; if (x < 0) x = w;
		if (y > h) y = 0; if (y < 0) y = h;
		x += gen_from_to(-10, 10);
		y += gen_from_to(-10, 10);
	}

	std::pair<float, float> get_koord() {
		return std::make_pair(x, y);
	}

private:
	float x, y, r;
	static std::random_device rd;
	std::mt19937 gen;
};

std::random_device Molecula::rd{};

class Visualizer {
public:
	Visualizer(const int count) :
		width{ 600.0f },
		height{ 600.0f },
		step_x{ width / 10.0f },
		step_y{ height / 10.0f },
		count{ count } {
		for (auto i = 0; i < count; ++i) {
			Molecula m{ width, height };
			moleculs.push_back(m);
		}
	}

	bool is_inside(Molecula m, const float xPos, const float yPos) {
		return ((m.get_koord().first < xPos) && (m.get_koord().first > (xPos - step_x)) && (m.get_koord().second < yPos) && (m.get_koord().second > (yPos - step_y)));
	}

	void run() {
		sf::RenderWindow window{ sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height)), "BROWN" };
		window.setFramerateLimit(10);

		while (window.isOpen()) {
			sf::Event event;

			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			for (auto i = step_x; i <= width; i += step_x) {
				for (auto j = step_y; j <= height; j += step_y) {
					int counter = 0;
					for (auto& m : moleculs) {
						if (is_inside(m, i, j)) {
							++counter;
						}
					}

					window.draw(make_rectangle(counter, i, j));
				}
			}

			for (auto& m : moleculs) {
				m.move(width, height);
				m.draw(window);
			}
			window.display();
		}
	}

	sf::RectangleShape make_rectangle(int counter, float i, float j) {
		sf::RectangleShape rectangle;
		rectangle.setPosition(sf::Vector2f(i - step_x, j - step_y));
		rectangle.setSize(sf::Vector2f(step_x, step_y));
		rectangle.setFillColor(sf::Color(0, 255 * counter / count * 3, 0));

		return rectangle;
	}

private:
	const float width;
	const float height;
	const float step_x;
	const float step_y;
	const int count;
	std::vector<Molecula> moleculs;
};

int main() {
	Visualizer v{ 30 };
	v.run();

	return 0;
}
