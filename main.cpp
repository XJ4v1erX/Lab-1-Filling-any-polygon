#include <cmath>
#include "Framebuffer.h"
#include  "Poligons.h"


int main() {
    Framebuffer framebuffer(800, 600);
    framebuffer.clear();


    framebuffer.renderBuffer();

    return 0;
}
