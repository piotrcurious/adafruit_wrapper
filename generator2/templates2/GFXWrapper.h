// GFXWrapper.h
#ifndef GFXWRAPPER_H
#define GFXWRAPPER_H

/**
 * @brief GFXWrapper class
 */
class GFXWrapper {
public:
    /**
     * @brief Constructor
     */
    GFXWrapper();

    /**
     * @brief Destructor
     */
    virtual ~GFXWrapper();

    /**
     * @brief Begin the graphics context
     */
    virtual void begin() = 0;

    /**
     * @brief End the graphics context
     */
    virtual void end() = 0;

    /**
     * @brief Draw a pixel at the specified coordinates
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param color Color of the pixel
     */
    virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

    /**
     * @brief Draw a line from (x1, y1) to (x2, y2)
     * @param x1 X-coordinate of the starting point
     * @param y1 Y-coordinate of the starting point
     * @param x2 X-coordinate of the ending point
     * @param y2 Y-coordinate of the ending point
     * @param color Color of the line
     */
    virtual void drawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) = 0;

    /**
     * @brief Draw a rectangle at the specified coordinates
     * @param x X-coordinate of the top-left corner
     * @param y Y-coordinate of the top-left corner
     * @param width Width of the rectangle
     * @param height Height of the rectangle
     * @param color Color of the rectangle
     */
    virtual void drawRect(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t color) = 0;

    /**
     * @brief Draw a filled rectangle at the specified coordinates
     * @param x X-coordinate of the top-left corner
     * @param y Y-coordinate of the top-left corner
     * @param width Width of the rectangle
     * @param height Height of the rectangle
     * @param color Color of the rectangle
     */
    virtual void fillRect(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t color) = 0;

    /**
     * @brief Draw a circle at the specified coordinates
     * @param x X-coordinate of the center
     * @param y Y-coordinate of the center
     * @param radius Radius of the circle
     * @param color Color of the circle
     */
    virtual void drawCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) = 0;

    /**
     * @brief Draw a filled circle at the specified coordinates
     * @param x X-coordinate of the center
     * @param y Y-coordinate of the center
     * @param radius Radius of the circle
     * @param color Color of the circle
     */
    virtual void fillCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) = 0;

    /**
     * @brief Set the text color
     * @param color Color of the text
     */
    virtual void setTextColor(uint16_t color) = 0;

    /**
     * @brief Set the text size
     * @param size Size of the text
     */
    virtual void setTextSize(uint8_t size) = 0;

    /**
     * @brief Draw a character at the specified coordinates
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param c Character to draw
     */
    virtual void drawChar(int16_t x, int16_t y, char c) = 0;

    /**
     * @brief Draw a string at the specified coordinates
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param str String to draw
     */
    virtual void drawString(int16_t x, int16_t y, const char* str) = 0;
};

#endif  // GFXWRAPPER_H
