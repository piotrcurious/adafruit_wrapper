// GFXWrapper.h
#ifndef GFXWRAPPER_H
#define GFXWRAPPER_H

class GFXWrapper {
public:
    void begin();
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    // ...
};

#endif  // GFXWRAPPER_H
