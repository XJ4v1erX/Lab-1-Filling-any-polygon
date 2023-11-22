//
// Created by javie on 13/7/2023.
//
#include <fstream>
#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Color.h"
#pragma once



class Framebuffer {
public:
    std::vector<Color> framebuffer;
    Color clearColor;
    Color currentColor;
    int screenWidth;
    int screenHeight;

public:
    Framebuffer(int width, int height) : screenWidth(width), screenHeight(height) {
        framebuffer.resize(screenWidth * screenHeight);
        clearColor = Color(0, 0, 0);
        currentColor = Color(255, 0, 0);
    }

    void clear() {
        std::fill(framebuffer.begin(), framebuffer.end(), clearColor);
    }

    void point(Vertex vertex) {
        if (vertex.x >= 0 && vertex.x < screenWidth &&
            vertex.y >= 0 && vertex.y < screenHeight) {
            int index = vertex.y * screenWidth + vertex.x;
            framebuffer[index] = currentColor;
        }
    }

    void line(Vertex start, Vertex end) {
        int x0 = start.x;
        int y0 = start.y;
        int x1 = end.x;
        int y1 = end.y;

        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            point(Vertex(x0, y0));

            if (x0 == x1 && y0 == y1)
                break;

            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x0 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y0 += sy;
            }
        }
    }

    void drawPolygon(const std::vector<Vertex>& vertices) {
        std::vector<Vertex>::size_type numVertices = vertices.size();
        if (numVertices < 2)
            return;

        for (std::vector<Vertex>::size_type i = 0; i < numVertices - 1; i++) {
            line(vertices[i], vertices[i + 1]);
        }

        // Draw line from the last vertex to the first vertex
        line(vertices[numVertices - 1], vertices[0]);
    }

    void fillPolygon(const std::vector<Vertex>& vertices) {
        std::vector<Vertex>::size_type numVertices = vertices.size();
        if (numVertices < 3)
            return;

        // Encontrar las coordenadas mínimas y máximas del polígono
        int minX = vertices[0].x;
        int maxX = vertices[0].x;
        int minY = vertices[0].y;
        int maxY = vertices[0].y;

        for (std::vector<Vertex>::size_type i = 1; i < numVertices; i++) {
            const Vertex& vertex = vertices[i];
            minX = std::min(minX, vertex.x);
            maxX = std::max(maxX, vertex.x);
            minY = std::min(minY, vertex.y);
            maxY = std::max(maxY, vertex.y);
        }

        // Rellenar el polígono
        for (int y = minY; y <= maxY; y++) {
            for (int x = minX; x <= maxX; x++) {
                if (isInsidePolygon(x, y, vertices)) {
                    point(Vertex(x, y));
                }
            }
        }
    }

    static bool isInsidePolygon(int x, int y, const std::vector<Vertex>& vertices) {
        std::vector<Vertex>::size_type numVertices = vertices.size();
        bool inside = false;

        for (std::vector<Vertex>::size_type i = 0, j = numVertices - 1; i < numVertices; j = i++) {
            if ((vertices[i].y > y) != (vertices[j].y > y) &&
                x < (vertices[j].x - vertices[i].x) * (y - vertices[i].y) / (vertices[j].y - vertices[i].y) + vertices[i].x) {
                inside = !inside;
            }
        }

        return inside;
    }

    void renderBuffer() {
        const int headerSize = 54;
        const int dataSize = screenWidth * screenHeight * 3;
        const int totalSize = headerSize + dataSize;

        std::vector<unsigned char> bmpData(totalSize, 0);

        // BMP header
        bmpData[0] = 'B';
        bmpData[1] = 'M';
        bmpData[2] = totalSize & 0xFF;
        bmpData[3] = (totalSize >> 8) & 0xFF;
        bmpData[4] = (totalSize >> 16) & 0xFF;
        bmpData[5] = (totalSize >> 24) & 0xFF;
        bmpData[10] = headerSize;
        bmpData[14] = 40;
        bmpData[18] = screenWidth & 0xFF;
        bmpData[19] = (screenWidth >> 8) & 0xFF;
        bmpData[20] = (screenWidth >> 16) & 0xFF;
        bmpData[21] = (screenWidth >> 24) & 0xFF;
        bmpData[22] = screenHeight & 0xFF;
        bmpData[23] = (screenHeight >> 8) & 0xFF;
        bmpData[24] = (screenHeight >> 16) & 0xFF;
        bmpData[25] = (screenHeight >> 24) & 0xFF;
        bmpData[26] = 1;
        bmpData[28] = 24;

        // BMP data
        int dataIndex = headerSize;
        for (int y = 0; y < screenHeight ; y++) {
            for (int x = 0; x < screenWidth; x++) {
                int index = y * screenWidth + x;
                const Color& color = framebuffer[index];
                bmpData[dataIndex++] = color.b;
                bmpData[dataIndex++] = color.g;
                bmpData[dataIndex++] = color.r;

            }
        }

        // Write BMP file
        std::ofstream bmpFile("../out.bmp", std::ios::binary);
        if (bmpFile.is_open()) {
            bmpFile.write(reinterpret_cast<char*>(&bmpData[0]), totalSize);
            bmpFile.close();
            std::cout << "Archivo BMP generado exitosamente." << std::endl;
        }
        else {
            std::cerr << "Error al generar el archivo BMP." << std::endl;
        }
    }
};