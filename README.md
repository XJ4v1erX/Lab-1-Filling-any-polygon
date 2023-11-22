# Lab-1-Filling-any-polygon
Este es el laboratorio 1, en el cual se debe crear un algoritmo que sea capaz de rellenar polígonos de más de 4 puntos sin el uso de librerías externas.

## Captura de Pantalla

![Out_bpm](iout.bmp)
## Polígonos

### Polígono 1
Puntos:
- (165, 380) (185, 360) (180, 330) (207, 345) (233, 330) (230, 360) (250, 380) (220, 385) (205, 410) (193, 383)

### Polígono 2
Puntos:
- (321, 335) (288, 286) (339, 251) (374, 302)

### Polígono 3
Puntos:
- (377, 249) (411, 197) (436, 249)

### Polígono 4
Puntos:
- (413, 177) (448, 159) (502, 88) (553, 53) (535, 36) (676, 37) (660, 52)
(750, 145) (761, 179) (672, 192) (659, 214) (615, 214) (632, 230) (580, 230)
(597, 215) (552, 214) (517, 144) (466, 180)

### Polígono 5 (Agujero en el Polígono 4)
Puntos:
- (682, 175) (708, 120) (735, 148) (739, 170)

## Requisitos para la Entrega (100 puntos)

- Crear un repositorio Git con los siguientes requisitos:
  - Puede dibujar todos los polígonos rellenados con sus colores de relleno y línea correspondiente.
  - Debe incluir un archivo `out.bmp` que pueda ser abierto en cualquier visor de imágenes.
  - No debe incluir el directorio `build`.
  - Debe incluir una rama llamada `Poligon-1` que dibuje únicamente el polígono 1 (amarillo con orilla blanca).
  - Debe incluir una rama llamada `Poligon-2` que dibuje únicamente el polígono 2 (azul con orilla blanca).
  - Debe incluir una rama llamada `Poligon-3` que dibuje únicamente el polígono 3 (rojo con orilla blanca).
  - Debe incluir una rama llamada `Poligon-4` que dibuje el polígono 4 con el polígono 5 como un agujero (verde con orilla blanca).
  - La rama `main` debe contener únicamente commits de fusiones de otras ramas.

## Estructura del Proyecto

- `main.cpp`: Archivo principal que contiene la función `main`.
- `Color.h`: Clase que define el color.
- `Framebuffer.h`: Clase que representa el framebuffer y contiene la lógica de dibujo y relleno de polígonos.
- `Vertex.h`: Definición de la estructura `Vertex` para representar puntos.
- `Polygons.h`: Archivo que define los polígonos y los colores.
- `CMakeLists.txt`: Archivo de configuración de CMake para el proyecto.

## Instrucciones de Uso

1. Clone el repositorio Git en su máquina local.
2. Compile y ejecute el programa.
3. Verifique la generación del archivo `out.bmp` en el directorio raíz del proyecto, que muestra la representación de los polígonos rellenados.

## Autor

- [Javier Ramírez]
