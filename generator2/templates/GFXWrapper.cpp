// GFXWrapper.cpp
#include "GFXWrapper.h"

void GFXWrapper::begin() {
    {{ hardware_impl_name }}_begin();
}

void GFXWrapper::drawPixel(int16_t x, int16_t y, uint16_t color) {
    {{ hardware_impl_name }}_drawPixel(x, y, color);
}
