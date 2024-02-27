#pragma once

#include "batch.hpp"

class PlayerCharacter
{
public:
	PlayerCharacter(const sf::Texture& texture, float minPositionX, float maxPositionX);
	void PlayerUpdate(float deltatime);
	void ProcessingInput(float deltatime)noexcept;
	void WorldConstrainingOnPositionX()noexcept;
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