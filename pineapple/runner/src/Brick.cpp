#include "Brick.h"

BrickContainer::BrickContainer() noexcept // smells with not noexcept
{

};

BrickContainer::~BrickContainer() noexcept
{

};

void BrickContainer::SetUp(sf::Texture* texture)
{
	m_texture = *texture;
	InitializeBricks();
}
	

void BrickContainer::Update()
{
	
};

void BrickContainer::InitializeBricks()
{
	m_brickObject.resize(13);
	float x = 0;
	float y = 100;
	for (int i = 0; i < m_brickObject.size(); i++)
	{

		m_brickObject[i].sprite.setTexture(m_texture);
		m_brickObject[i].color = sf::Color::Red;
		m_brickObject[i].positionX = x;
		m_brickObject[i].positionY = y;
		x += 100;
		m_brickObject[i].sprite.setPosition(m_brickObject[i].positionX, m_brickObject[i].positionY);
		m_brickObject[i].sprite.setColor(m_brickObject[i].color);
	};
}