#pragma once

#include "batch.hpp"
#include <vector>
#include "Ball.h"

class BrickContainer
{
public:
	BrickContainer(const sf::Texture& texture, int numBricks, 
	float startX, float startY, float spacingX);
	void Update() noexcept;
	void Restart();
	void Draw(sf::RenderWindow& window);
	void InitializeBricks(const sf::Texture& texture, int numBricks, float startX, float startY, float spacingX);
	void deleteBrickAtIndex(int index) noexcept;
	bool areBricksGone() const;
	std::vector<int> checkCollisionsWithBall(const Ball& ball);
private:
	std::vector<sf::Sprite> m_brickSprites;
	sf::Texture m_texture;
	int m_numBricks;
	float m_startX;
	float m_startY;
	float m_spacingX;
};