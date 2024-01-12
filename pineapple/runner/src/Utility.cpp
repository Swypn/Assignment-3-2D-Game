#include "Utility.h"

float toFloat(unsigned int value) noexcept {
    return static_cast<float>(value);
}

int toInt(float value) noexcept {
    return static_cast<int>(value);
}

int toInt(size_t value) noexcept {
    return static_cast<int>(value);
}