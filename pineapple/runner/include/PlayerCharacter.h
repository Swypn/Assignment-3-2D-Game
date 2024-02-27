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
	bool SetLeftPressed(bool state) noexcept;
	bool SetRightPressed(bool state) noexcept;
private:
	bool pressedLeft;
	bool pressedRight;
	sf::Sprite m_playerSprite;
	const float defualtMovmentSpeed;
	const float positionY;
	float positionX;
	float minPositionX, maxPositionX;
};