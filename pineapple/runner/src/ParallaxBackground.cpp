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
	float fallingSpeed = 125;
	for (int i = 0; i < m_fallingStarYellow.size(); i++)
	{
		m_fallingStarYellow[i].sprite.setPosition(m_fallingStarYellow[i].positionX, m_fallingStarYellow[i].positionY += fallingSpeed * deltatime);
		fallingSpeed += 25;
	}
	fallingSpeed = 100;
	for (int i = 0; i < m_fallingStarRed.size(); i++)
	{
		m_fallingStarRed[i].sprite.setPosition(m_fallingStarRed[i].positionX, m_fallingStarRed[i].positionY += fallingSpeed * deltatime);
		fallingSpeed -= 15;
	}
#pragma warning(pop)
}

void parallaxBackground::Restart()
{
	InitializeFallingStars(sf::Color::Yellow, 100.0f, -100.0f, m_yellowStarCount, m_fallingStarYellow);
	InitializeFallingStars(sf::Color::Red, 250.0f, -300.0f, m_redStarCount, m_fallingStarRed);
}
