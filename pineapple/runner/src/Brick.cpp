#include "Brick.h"

BrickContainer::BrickContainer(const sf::Texture& texture, int numBricks, 
	float startX, float startY, float spacingX)
	: m_texture(texture), m_numBricks(numBricks), m_startX(startX), m_startY(startY), m_spacingX(spacingX)
{
		InitializeBricks(texture, numBricks, startX, startY, spacingX);
};

void BrickContainer::Update() noexcept
{

};

void BrickContainer::Restart()
{
	InitializeBricks(m_texture, m_numBricks, m_startX, m_startY, m_spacingX);
};

void BrickContainer::InitializeBricks(const sf::Texture& texture, int numBricks, float startX, float startY, float spacingX)
{

	m_brickSprites.clear();
	float x = startX;
	for (int i = 0; i < numBricks; ++i) {
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setColor(sf::Color::Red);
		sprite.setPosition(x, startY);
		m_brickSprites.push_back(sprite);
		x += sprite.getLocalBounds().width + spacingX;
	}
}