#include "ParallaxBackground.h"

parallaxBackground::parallaxBackground(const sf::Texture& texture)
	: m_texture(texture), m_yellowStarCount(4), m_redStarCount(3)
{
	InitializeFallingStars(sf::Color::Yellow, 100.0f, -100.0f, m_yellowStarCount, m_fallingStarYellow);
	InitializeFallingStars(sf::Color::Red, 250.0f, -300.0f, m_redStarCount, m_fallingStarRed);
}

void parallaxBackground::InitializeFallingStars(sf::Color color, float startX, float startY, int count, std::vector<parallaxPart>& stars)
{
	stars.clear();
	float x = startX;
	for (int i = 0; i < count; ++i) {
		parallaxPart part;
		part.sprite.setTexture(m_texture);
		part.sprite.setColor(color);
		part.positionX = x;
		part.positionY = startY;
		part.sprite.setPosition(part.positionX, part.positionY);
		part.sprite.setScale(0.5f, 0.5f);
		stars.push_back(part);
		x += 350.0f; // Adjust for the next star
	}
}

void parallaxBackground::Update(float deltatime, float windowHeight)
{
	UpdateStars(m_fallingStarYellow, deltatime, windowHeight, 125.0f, 25.0f);
	UpdateStars(m_fallingStarRed, deltatime, windowHeight, 100.0f, -15.0f);
}

void parallaxBackground::UpdateStars(std::vector<parallaxPart>& stars, float deltaTime, float windowHeight, float initialSpeed, float speedIncrement)
{
	float fallingSpeed = initialSpeed;
	for (auto& star : stars) {
		star.positionY += fallingSpeed * deltaTime;
		if (star.positionY >= windowHeight) {
			star.positionY = -100.0f; // Reset star position
		}
		star.sprite.setPosition(star.positionX, star.positionY);
		fallingSpeed += speedIncrement;
	}
}

void parallaxBackground::Draw(sf::RenderWindow& window)
{
	for (const auto& star : m_fallingStarYellow) {
		window.draw(star.sprite);
	}
	for (const auto& star : m_fallingStarRed) {
		window.draw(star.sprite);
	}
}

void parallaxBackground::Restart()
{
	InitializeFallingStars(sf::Color::Yellow, 100.0f, -100.0f, m_yellowStarCount, m_fallingStarYellow);
	InitializeFallingStars(sf::Color::Red, 250.0f, -300.0f, m_redStarCount, m_fallingStarRed);
}