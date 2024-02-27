#pragma once

#include "batch.hpp"

namespace Utility 
{
	constexpr float toFloat(unsigned int value) noexcept;
	constexpr int toInt(float value) noexcept;
	constexpr int toInt(size_t value) noexcept;

	bool AxisAlignedBoundingBox(const sf::Sprite& box1, const sf::Sprite& box2);
}
