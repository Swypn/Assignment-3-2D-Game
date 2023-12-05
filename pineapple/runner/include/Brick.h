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
	BrickContainer() noexcept;
	~BrickContainer() noexcept;
	void SetUp(sf::Texture* texture);
	void Update();
	void InitializeBricks();
	std::vector<Brick> m_brickObject;
private:
	sf::Texture m_texture;
};