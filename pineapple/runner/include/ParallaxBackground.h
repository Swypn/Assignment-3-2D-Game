#pragma once
#include "batch.hpp"
#include <vector>

struct parallaxParts
{
	sf::Sprite sprite;
	sf::Color color;
	float positionX{};
	float positionY{};
};

class parallaxBackground
{
public:
	parallaxBackground(const sf::Texture& texture);
	std::vector<parallaxParts> m_fallingStarYellow;
	std::vector<parallaxParts> m_fallingStarRed;
	void InitilizeFallingStar();
	void Update(float deltatime);
private:
	sf::Texture m_texture;
};