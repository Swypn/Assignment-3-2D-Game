#pragma once
#include "batch.hpp"
#include <vector>

struct parallaxPart
{
	sf::Sprite sprite;
	float positionX{};
	float positionY{};
};

class parallaxBackground
{
public:
	parallaxBackground(const sf::Texture& texture);
	std::vector<parallaxPart> m_fallingStarYellow;
	std::vector<parallaxPart> m_fallingStarRed;
	void InitializeFallingStars(sf::Color color, float startX, float startY, int count, std::vector<parallaxPart>& stars);
	void Update(float deltatime, float windowHeight);
	void UpdateStars(std::vector<parallaxPart>& stars, float deltaTime, float windowHeight,
		float initialSpeed, float speedIncrement);
	void Draw(sf::RenderWindow& window);
	void Restart();
private:
	sf::Texture m_texture;
	int m_yellowStarCount;
	int m_redStarCount;
};