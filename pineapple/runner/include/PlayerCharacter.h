#pragma once

#include "batch.hpp"

class PlayerCharacter
{
public:
	PlayerCharacter() noexcept;
	void SetUp(const sf::Texture* texture, float min, float max);
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