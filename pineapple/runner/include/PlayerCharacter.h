#pragma once

#include "batch.hpp"
#include "Ball.h"
#include "Utility.h"

class PlayerCharacter
{
public:
	PlayerCharacter(const sf::Texture& texture, float minPositionX, float maxPositionX);
	void PlayerUpdate(float deltatime);
	void ProcessingInput(float deltatime)noexcept;
	void WorldConstrainingOnPositionX()noexcept;
	bool CheckCollisionWithBall(const Ball& ball) const;
	void Draw(sf::RenderWindow& window);
	void Restart()noexcept;
	sf::Sprite m_playerSprite;
	bool pressedLeft;
	bool pressedRight;
private:
	const float defualtMovmentSpeed;
	const float positionY;
	float positionX;
	float minPositionX, maxPositionX;
};