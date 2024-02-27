#pragma once

#include "batch.hpp"
#include <vector>

class BrickContainer
{
public:
	BrickContainer(const sf::Texture& texture, int numBricks, 
	float startX, float startY, float spacingX);
	void Update() noexcept;
	void Restart();
	void InitializeBricks(const sf::Texture& texture, int numBricks, float startX, float startY, float spacingX);
	std::vector<sf::Sprite> m_brickSprites;
private:
	sf::Texture m_texture;
	int m_numBricks;
	float m_startX;
	float m_startY;
	float m_spacingX;
};