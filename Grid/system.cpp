#include "system.hpp"
#include <iostream>

// =============================================================================

void System::initialize() {
	auto side = m_particles.size();
	
	for (auto i = 0U; i < side; ++i) {
		for (auto j = 0U; j < side; ++j) {
			if (i < side - 1) {
				m_links.push_back(Link(particle(i, j), particle(i + 1, j), 1.0f));
			}
			if (j < side - 1) {
				m_links.push_back(Link(particle(i, j), particle(i, j + 1), 1.0f));
				if (i < side - 1) {
					m_links.push_back(Link(particle(i, j), particle(i + 1, j + 1), 1.0f));
				}
				if (i > 0) {
					m_links.push_back(Link(particle(i, j), particle(i - 1, j + 1), 1.0f));
				}
			}
		}
	}
}

// =============================================================================

void System::push(const sf::Vector2f force) const noexcept {
	auto side = m_particles.size();

	for (auto i = 0U; i < side; ++i) {
		for (auto j = 0U; j < side; ++j) {
			m_particles[i][j]->move(force);
		}
	}
}

// =============================================================================

void System::update() const noexcept {
	for (auto i = 0U; i < m_particles.size(); ++i) {
		for (int j = 0; j < 10; ++j) {
			m_particles[i][j]->move(0.25f);

			if (m_particles[i][j]->position().y + m_particles[i][j]->radius() > m_max_point.y)
			{
				m_particles[i][j]->set_y(m_max_point.y - m_particles[i][j]->radius());
			}

			if (m_particles[i][j]->position().y - m_particles[i][j]->radius() < m_min_point.y)
			{
				m_particles[i][j]->set_y(m_min_point.y + m_particles[i][j]->radius());
			}

			if (m_particles[i][j]->position().x + m_particles[i][j]->radius() > m_max_point.x)
			{
				m_particles[i][j]->set_x(m_max_point.x - m_particles[i][j]->radius());
			}

			if (m_particles[i][j]->position().x - m_particles[i][j]->radius() < m_min_point.x)
			{
				m_particles[i][j]->set_x(m_min_point.x + m_particles[i][j]->radius());
			}
		}
	}

	for (auto i = 0U; i < m_links.size(); ++i)
	{
		m_links[i].update();
	}
}