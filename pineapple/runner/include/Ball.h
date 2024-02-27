#pragma once
#include "batch.hpp"
#include "Utility.h"
class Ball 
{
public:
	Ball(const sf::Texture& texture, int rectWidth, int rectHeight, int rectLeft, int rectTop);
	void BallUpdate(float deltatime);
	float Length(const sf::Vector2f& rhs) noexcept;
	void WorldConstraining(float posX, float posY) noexcept;
	void Draw(sf::RenderWindow& window);
	void Restart();
	void FlipVertcialDirection() noexcept;
	void IncreaseSpeed(float increment) noexcept;
	sf::Vector2f GetPosition() const;
	sf::Sprite GetSprite() const noexcept;
	sf::Vector2f Normalized(const sf::Vector2f& rhs);
private:
	sf::Vector2f m_direction;
	sf::Sprite m_ballSprite;
	sf::IntRect worldBounds;
	float m_speed = 200.0f;
	float positionX = 500.0f;
	float positionY = 400.0f;
};