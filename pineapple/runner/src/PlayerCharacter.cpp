#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(const sf::Texture& texture, float min, float max)
	: defualtMovmentSpeed(700.0f), positionY(650.0f), 
	positionX(500.0f), minPositionX(min), maxPositionX(max)
{
	m_playerSprite.setTexture(texture);
	m_playerSprite.setPosition(positionX, positionY);
	m_playerSprite.setScale(1.0f, 0.5f);
	pressedLeft = false;
	pressedRight = false;
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
}
bool PlayerCharacter::CheckCollisionWithBall(const Ball& ball) const
{
	return Utility::AxisAlignedBoundingBox(this->m_playerSprite, ball.GetSprite());
}
void PlayerCharacter::Draw(sf::RenderWindow& window)
{
	window.draw(m_playerSprite);
};

void PlayerCharacter::Restart() noexcept
{
	positionX = 500.0f;
}