#pragma once

//
// Created by javie on 13/7/2023.
//

Color color1(255, 255, 0);  // Amarillo
Color color2(255, 255, 255);      // Blanco
Color color3(0, 0, 255);    // Azul
Color color4(255, 0, 0);    // Rojo
Color color5(0, 255, 0);    // verde
Color color6(0, 0, 0); //negro

void drawAndFillPolygon1(Framebuffer& framebuffer) {
    std::vector<Vertex> vertices1{
            {165, 380},
            {185, 360},
            {180, 330},
            {207, 345},
            {233, 330},
            {230, 360},
            {250, 380},
            {220, 385},
            {205, 410},
            {193, 383}
    };

    framebuffer.currentColor = color1;
    framebuffer.fillPolygon(vertices1);
    framebuffer.currentColor = color2;
    framebuffer.drawPolygon(vertices1);
}
void drawAndFillPolygon2(Framebuffer& framebuffer) {
    std::vector<Vertex> vertices2{
            {321, 335},
            {288, 286},
            {339, 251},
            {374, 302}
    };

    framebuffer.currentColor = color3;
    framebuffer.fillPolygon(vertices2);
    framebuffer.currentColor = color2;
    framebuffer.drawPolygon(vertices2);

}
void drawAndFillPolygon3(Framebuffer& framebuffer) {
    std::vector<Vertex> vertices3{
            {377, 249},
            {411, 197},
            {436, 249}
    };

    framebuffer.currentColor = color4;
    framebuffer.fillPolygon(vertices3);
    framebuffer.currentColor = color2;
    framebuffer.drawPolygon(vertices3);

}
//LAB1_FILLING_ANY_POLYGON_POLYGONS_H