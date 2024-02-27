#include "Utility.h"
#include <cstddef>
#pragma warning(push)
#pragma warning(disable : 26472)

constexpr float Utility::toFloat(unsigned int value) noexcept {
    return static_cast<float>(value);
}

constexpr int Utility::toInt(float value) noexcept {
    return static_cast<int>(value);
}

constexpr int Utility::toInt(size_t value) noexcept {
    return static_cast<int>(value);
}

bool Utility::AxisAlignedBoundingBox(const sf::Sprite& box1, const sf::Sprite& box2) {
    const bool collisionX = box1.getPosition().x + box1.getGlobalBounds().width >= box2.getPosition().x &&
        box2.getPosition().x + box2.getGlobalBounds().width >= box1.getPosition().x;
    const bool collisionY = box1.getPosition().y + box1.getGlobalBounds().height >= box2.getPosition().y &&
        box2.getPosition().y + box2.getGlobalBounds().height >= box1.getPosition().y;

    return collisionX && collisionY;
}

#pragma warning(pop)