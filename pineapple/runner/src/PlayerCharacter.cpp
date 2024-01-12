#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() noexcept
	: defualtMovmentSpeed(700.0f), positionY(650.0f)
{
	positionX = 0.0f;
	minPositionX = 0;
	maxPositionX = 0;
	pressedLeft = false;
	pressedRight = false;
};

void PlayerCharacter::SetUp(const sf::Texture* texture, float min, float max)
{
	if(texture)
	{
		m_playerSprite.setTexture(*texture);
		m_playerSprite.setPosition(positionX, positionY);
		m_playerSprite.setScale(1.0f, 0.5f);
		minPositionX = min;
		maxPositionX = max;
		positionX = 500.0f;
	}

};

void PlayerCharacter::PlayerUpdate(float deltatime)
{
	ProcessingInput(deltatime);
	m_playerSprite.setPosition(positionX, positionY);
	WorldConstrainingOnPositionX();
};

void PlayerCharacter::ProcessingInput(float deltatime)noexcept
{
	if(pressedLeft)
	{
		positionX += -defualtMovmentSpeed * deltatime;
	}
	if(pressedRight)
	{
		positionX += defualtMovmentSpeed * deltatime;
	}
};

void PlayerCharacter::WorldConstrainingOnPositionX() noexcept
{
	if(positionX < minPositionX)
	{
		positionX = 0.0f;
	}
	if(positionX >= maxPositionX - 150.0f)
	{
		positionX = maxPositionX - 150.0f;
	}
};

void PlayerCharacter::Restart() noexcept
{
	positionX = 500.0f;
}