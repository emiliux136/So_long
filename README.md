# 🎮 so_long - My first 2D Game

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Graphics](https://img.shields.io/badge/Library-MiniLibX-orange.svg)
![Status](https://img.shields.io/badge/Status-Completed-green.svg)

Un pequeño motor de juego en 2D desarrollado en C utilizando la librería **MiniLibX**. Este proyecto es una introducción fundamental a la programación gráfica, el manejo de texturas y la gestión de eventos de teclado/ratón.

---

## 🕹️ El Proyecto

El objetivo es crear un juego de perspectiva superior donde un personaje debe recoger todos los objetos coleccionables y alcanzar la salida en el menor número de movimientos posible.

### Retos Técnicos Superados
* **Gestión de Ventanas:** Renderizado de frames y manejo de buffers de imagen.
* **Parsing de Mapas:** Validación de archivos `.ber` (muros cerrados, camino válido, elementos requeridos).
* **Algoritmia:** Implementación de *Flood Fill* para verificar que el mapa sea jugable antes de iniciar.
* **Event Handling:** Control de entradas de teclado (WASD/Flechas) y cierre limpio de procesos.

---

## 🛠️ Tecnologías Clave

| Componente | Herramienta |
| :--- | :--- |
| **Gráficos** | MiniLibX (Framework simple de X-Window) |
| **Imágenes** | Gestión de archivos `.xpm` y carga de texturas. |
| **Memoria** | Gestión estricta de punteros para evitar leaks en el renderizado. |
| **Mapa** | Matriz bidimensional dinámica. |

---

## 🔍 Estructura de Control

1.  **Validación:** Comprobación de que el mapa es rectangular, rodeado de muros y tiene 1 salida, 1 jugador y al menos 1 coleccionable.
2.  **Inicialización:** Configuración de la conexión con el servidor gráfico y carga de sprites.
3.  **Game Loop:** Renderizado dinámico basado en la posición del jugador y actualización del contador de movimientos en la terminal (o ventana).
4.  **Cierre Limpio:** Destrucción de imágenes y ventanas para liberar memoria al presionar `ESC` o el botón de cierre.

---

## 👤 Contacto
**Emilio** - [LinkedIn](https://www.linkedin.com/in/emilio-garcía-burgos-85a3a6334/)

---
> **Nota:** Este proyecto incluye una gestión de errores personalizada para notificar al usuario cualquier fallo en el formato del mapa o en la carga de assets.
