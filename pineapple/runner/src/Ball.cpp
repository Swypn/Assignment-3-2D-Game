#include "Ball.h"

Ball::Ball(const sf::Texture& texture, int rectWidth, int rectHeight, int rectLeft, int rectTop)
{
	m_ballSprite.setTexture(texture);
	m_ballSprite.setPosition(positionX, positionY);
	m_ballSprite.setScale(1.0f, 1.0f);

	worldBounds = { rectLeft, rectTop, rectWidth, rectHeight };
	m_direction = { positionX, positionY };
};

void Ball::BallUpdate(float deltatime)
{
	WorldConstraining(positionX, positionY);
	m_direction = Normalized(m_direction);
	positionX += m_direction.x * m_speed * deltatime;
	positionY += m_direction.y * m_speed * deltatime;
	m_ballSprite.setPosition(positionX, positionY);
};

float Ball::Length(const sf::Vector2f& rhs) noexcept
{
	return std::sqrtf(rhs.x * rhs.x + rhs.y * rhs.y);
};

sf::Vector2f Ball::Normalized(const sf::Vector2f& rhs) {
	const float length = 1.0f / Length(rhs);
	const float x = rhs.x * length;
	const float y = rhs.y * length;
	return sf::Vector2f{ x, y };
}

void Ball::WorldConstraining(float posX, float posY) noexcept
{
	if (posX < static_cast<float>(worldBounds.left))
	{
		m_direction.x = -m_direction.x;
	}
	if (posX >= static_cast<float>(worldBounds.width - 50))
	{
		m_direction.x = -m_direction.x;
	}
	if (posY < static_cast<float>(worldBounds.top))
	{
		m_direction.y = -m_direction.y;
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(m_ballSprite);
}

void Ball::Restart()
{
	m_speed = 200.0f;
	positionX = 500.0f;
	positionY = 400.0f;
	m_direction = { positionX, positionY };
	m_ballSprite.setPosition(positionX, positionY);
}

void Ball::FlipVertcialDirection() noexcept
{
	m_direction.y = -m_direction.y;
}

void Ball::IncreaseSpeed(float increment) noexcept
{
	m_speed += increment;
}

sf::Vector2f Ball::GetPosition() const
{
	return m_ballSprite.getPosition();
}

sf::Sprite Ball::GetSprite() const noexcept
{
	return m_ballSprite;
}
