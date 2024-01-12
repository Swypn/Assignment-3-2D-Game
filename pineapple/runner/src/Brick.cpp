#include "Brick.h"

BrickContainer::BrickContainer() noexcept 
{

};

void BrickContainer::SetUp(sf::Texture* texture)
{
	m_texture = *texture;
	InitializeBricks();
}
	

void BrickContainer::Update() noexcept
{
	
};

void BrickContainer::InitializeBricks()
{
	m_brickObject.clear();
	m_brickObject.resize(13);
	float x = 0;
	constexpr float y = 100;

	for(auto& bricks : m_brickObject)
	{
		bricks.sprite.setTexture(m_texture);
		bricks.color = sf::Color::Red;
		bricks.positionX = x;
		bricks.positionY = y;
		x += 100;
		bricks.sprite.setPosition(bricks.positionX, bricks.positionY);
		bricks.sprite.setColor(bricks.color);
	}
}