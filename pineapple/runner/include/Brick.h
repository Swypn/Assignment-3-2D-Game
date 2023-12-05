#pragma once

#include "batch.hpp"
#include <vector>
struct Brick
{
	sf::Sprite sprite;
	sf::Color color;
	float positionX, positionY;
};

class BrickContainer
{
public:
	BrickContainer();
	~BrickContainer();
	void SetUp(sf::Texture* texture);
	void Update();
	void Restart();
	std::vector<Brick> m_brickObject;
private:
	sf::Texture m_texture;
};