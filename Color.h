//
// Created by javie on 13/7/2023.
//

#include <iostream>
#pragma once

class Color {
public:
    unsigned char r, g, b;

    Color(unsigned char red, unsigned char green, unsigned char blue) {
        r = (red > 255) ? 255 : ((red < 0) ? 0 : red);
        g = (green > 255) ? 255 : ((green < 0) ? 0 : green);
        b = (blue > 255) ? 255 : ((blue < 0) ? 0 : blue);
    }

    Color() : r(0), g(0), b(0) {}

    friend std::ostream& operator<<(std::ostream& os, const Color& color) {
        os << "RGB(" << static_cast<int>(color.r) << ", "
           << static_cast<int>(color.g) << ", "
           << static_cast<int>(color.b) << ")";
        return os;
    }

    Color operator+(const Color& other) const {
        unsigned char sumR = r + other.r;
        unsigned char sumG = g + other.g;
        unsigned char sumB = b + other.b;

        sumR = (sumR > 255) ? 255 : sumR;
        sumG = (sumG > 255) ? 255 : sumG;
        sumB = (sumB > 255) ? 255 : sumB;

        return {sumR, sumG, sumB};
    }

    Color operator*(float factor) const {
        auto scaledR = static_cast<unsigned char>(static_cast<float>(r) * factor);
        auto scaledG = static_cast<unsigned char>(static_cast<float>(g) * factor);
        auto scaledB = static_cast<unsigned char>(static_cast<float>(b) * factor);

        scaledR = (scaledR > 255) ? 255 : scaledR;
        scaledG = (scaledG > 255) ? 255 : scaledG;
        scaledB = (scaledB > 255) ? 255 : scaledB;

        return {scaledR,scaledG , scaledB};
    }
};



//LAB1_FILLING_ANY_POLYGON_COLOR_H