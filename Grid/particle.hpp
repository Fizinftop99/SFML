#pragma once

#include <SFML/Graphics.hpp>

class Particle
{
public:

	Particle() noexcept = default;

	explicit Particle(
		const sf::Vector2f position, const sf::Vector2f previous_position,
		const sf::Vector2f acceleration, const float radius) noexcept :
		m_position(position), m_previous_position(previous_position),
		m_acceleration(acceleration), m_radius(radius)
	{}

	~Particle() noexcept = default;

public:

	const auto position() const noexcept
	{
		return m_position;
	}

	const auto radius() const noexcept
	{
		return m_radius;
	}

public:

	void set_x(const float x) noexcept
	{
		m_position.x = x;
	}

	void set_y(const float y) noexcept
	{
		m_position.y = y;
	}

public:

	void move(const sf::Vector2f delta) noexcept;

	void move(const float dt) noexcept;

private:

	sf::Vector2f m_position;
	sf::Vector2f m_previous_position;
	sf::Vector2f m_acceleration;

	float m_radius;
};