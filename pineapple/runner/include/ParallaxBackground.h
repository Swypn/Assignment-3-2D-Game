#pragma once
#include "batch.hpp"
#include <vector>

struct parallaxParts
{
	sf::Sprite sprite;
	sf::Color color;
	float positionX, positionY;
};

class parallaxBackground
{
public:
	parallaxBackground() noexcept;
	~parallaxBackground() noexcept;
	std::vector<parallaxParts> m_fallingStarYellow;
	std::vector<parallaxParts> m_fallingStarRed;
	void SetUp(sf::Texture* texture);
	void InitilizeFallingStar();
	void Update(float deltatime);
private:
	sf::Texture m_texture;
};