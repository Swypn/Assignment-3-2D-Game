#include "Utility.h"
#include <cstddef>
#pragma warning(push)
#pragma warning(disable : 26472)

constexpr float toFloat(unsigned int value) noexcept {
    return static_cast<float>(value);
}

constexpr int toInt(float value) noexcept {
    return static_cast<int>(value);
}

constexpr int toInt(size_t value) noexcept {
    return static_cast<int>(value);
}

#pragma warning(pop)