// HardwareImplementation.cpp
#include "GFXWrapper.h"

class {{ hardware_impl_name }} : public GFXWrapper {
public:
    void begin() override {
        // Hardware-specific implementation
    }

    void drawPixel(int16_t x, int16_t y, uint16_t color) override {
        // Hardware-specific implementation
    }
};
