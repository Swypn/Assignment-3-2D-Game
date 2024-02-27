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

void parallaxBackground::Update(float deltatime)
{
#pragma warning(push)
#pragma warning(disable : 26446)
	float fallingSpeed = 125.0f;
	for (auto& star : m_fallingStarYellow) {
		star.positionY += fallingSpeed * deltatime;
		star.sprite.setPosition(star.positionX, star.positionY);
		fallingSpeed += 25.0f;
	}

	fallingSpeed = 100.0f;
	for (auto& star : m_fallingStarRed) {
		star.positionY += fallingSpeed * deltatime;
		star.sprite.setPosition(star.positionX, star.positionY);
		fallingSpeed -= 15.0f;
	}
#pragma warning(pop)
}

void parallaxBackground::Restart()
{
	InitializeFallingStars(sf::Color::Yellow, 100.0f, -100.0f, m_yellowStarCount, m_fallingStarYellow);
	InitializeFallingStars(sf::Color::Red, 250.0f, -300.0f, m_redStarCount, m_fallingStarRed);
}
