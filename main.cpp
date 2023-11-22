#include <cmath>
#include "Framebuffer.h"
#include  "Polygons.h"


int main() {
    Framebuffer framebuffer(800, 600);
    framebuffer.clear();

    drawAndFillPolygon1(framebuffer);

    framebuffer.renderBuffer();

    return 0;
}
