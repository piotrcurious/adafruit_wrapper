// GFXWrapper.cpp
#include "GFXWrapper.h"

GFXWrapper::GFXWrapper() {}

GFXWrapper::~GFXWrapper() {}

void GFXWrapper::begin() {
    {{ hardware_impl_name }}_begin();
}

void GFXWrapper::end() {
    {{ hardware_impl_name }}_end();
}

void GFXWrapper::drawPixel(int16_t x, int16_t y, uint16_t color) {
    {{ hardware_impl_name }}_drawPixel(x, y, color);
}

void GFXWrapper::drawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
    {{ hardware_impl_name }}_drawLine(x1, y1, x2, y2, color);
}

void GFXWrapper::drawRect(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t color) {
    {{ hardware_impl_name }}_drawRect(x, y, width, height, color);
}

void GFXWrapper::fillRect(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t color) {
    {{ hardware_impl_name }}_fillRect(x, y, width, height, color);
}

void GFXWrapper::drawCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) {
    {{ hardware_impl_name }}_drawCircle(x, y, radius, color);
}

void GFXWrapper::fillCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) {
    {{ hardware_impl_name }}_fillCircle(x, y, radius, color);
}

void GFXWrapper::setTextColor(uint16_t color) {
    {{ hardware_impl_name }}_setTextColor(color);
}

void GFXWrapper::setTextSize(uint8_t size) {
    {{ hardware_impl_name }}_setTextSize(size);
}

void GFXWrapper::drawChar(int16_t x, int16_t y, char c) {
    {{ hardware_impl_name }}_drawChar(x, y, c);
}

void GFXWrapper::drawString(int16_t x, int16_t y, const char* str) {
    {{ hardware_impl_name }}_drawString(x, y, str);
}
