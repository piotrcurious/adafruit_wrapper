// HardwareImplementation.h
#ifndef HARDWAREIMPLEMENTATION_H
#define HARDWAREIMPLEMENTATION_H

#include "GFXWrapper.h"

/**
 * @brief HardwareImplementation class
 */
class HardwareImplementation : public GFXWrapper {
public:
    /**
     * @brief Constructor
     */
    HardwareImplementation();

    /**
     * @brief Destructor
     */
    virtual ~HardwareImplementation();

    /**
     * @brief Begin the graphics context
     */
    void begin() override;

    /**
     * @brief End the graphics context
     */
    void end() override;

    /**
     * @brief Draw a pixel at the specified coordinates
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param color Color of the pixel
     */
    void drawPixel(int16_t x, int16_t y, uint16_t color) override;

    /**
     * @brief Draw a line from (x1, y1) to (x2, y2)
     * @param x1 X-coordinate of the starting point
     * @param y1 Y-coordinate of the starting point
     * @param x2 X-coordinate of the ending point
     * @param y2 Y-coordinate of the ending point
     * @param color Color of the line
     */
    void drawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) override;

    /**
     * @brief Draw a rectangle at the specified coordinates
     * @param x X-coordinate of the top-left corner
     * @param y Y-coordinate of the top-left corner
     * @param width Width of the rectangle
     * @param height Height of the rectangle
     * @param color Color of the rectangle
     */
    void drawRect(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t color) override;

    /**
     * @brief Draw a filled rectangle at the specified coordinates
     * @param x X-coordinate of the top-left corner
     * @param y Y-coordinate of the top-left corner
     * @param width Width of the rectangle
     * @param height Height of the rectangle
     * @param color Color of the rectangle
     */
    void fillRect(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t color) override;

        /**
     * @brief Draw a circle at the specified coordinates
     * @param x X-coordinate of the center
     * @param y Y-coordinate of the center
     * @param radius Radius of the circle
     * @param color Color of the circle
     */
    void drawCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) override;

    /**
     * @brief Draw a filled circle at the specified coordinates
     * @param x X-coordinate of the center
     * @param y Y-coordinate of the center
     * @param radius Radius of the circle
     * @param color Color of the circle
     */
    void fillCircle(int16_t x, int16_t y, int16_t radius, uint16_t color) override;

    /**
     * @brief Set the text color
     * @param color Color of the text
     */
    void setTextColor(uint16_t color) override;

    /**
     * @brief Set the text size
     * @param size Size of the text
     */
    void setTextSize(uint8_t size) override;

    /**
     * @brief Draw a character at the specified coordinates
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param c Character to draw
     */
    void drawChar(int16_t x, int16_t y, char c) override;

    /**
     * @brief Draw a string at the specified coordinates
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param str String to draw
     */
    void drawString(int16_t x, int16_t y, const char* str) override;
};

#endif  // HARDWAREIMPLEMENTATION_H
