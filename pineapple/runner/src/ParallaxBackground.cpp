#include "ParallaxBackground.h"

parallaxBackground::parallaxBackground() noexcept
{
}

void parallaxBackground::SetUp(const sf::Texture* texture) 
{
	if(texture)
	{
		m_texture = *texture;
		InitilizeFallingStar();
	}
}

void parallaxBackground::InitilizeFallingStar()
{
	m_fallingStarYellow.clear();
	m_fallingStarRed.clear();
	m_fallingStarYellow.resize(4);
	m_fallingStarRed.resize(3);
	float x = 100;
	float y = -100;

	for(auto& fallingYellowStars : m_fallingStarYellow)
	{
		fallingYellowStars.sprite.setTexture(m_texture);
		fallingYellowStars.color = sf::Color::Yellow;
		fallingYellowStars.positionX = x;
		fallingYellowStars.positionY = y;
		x += 350;
		fallingYellowStars.sprite.setPosition(fallingYellowStars.positionX, fallingYellowStars.positionY);
		fallingYellowStars.sprite.setScale(0.5f, 0.5f);
		fallingYellowStars.sprite.setColor(fallingYellowStars.color);
	}
	y = -300;
	x = 250;

	for (auto& fallingRedStars : m_fallingStarRed)
	{
		fallingRedStars.sprite.setTexture(m_texture);
		fallingRedStars.color = sf::Color::Yellow;
		fallingRedStars.positionX = x;
		fallingRedStars.positionY = y;
		x += 350;
		fallingRedStars.sprite.setPosition(fallingRedStars.positionX, fallingRedStars.positionY);
		fallingRedStars.sprite.setScale(0.5f, 0.5f);
		fallingRedStars.sprite.setColor(fallingRedStars.color);
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