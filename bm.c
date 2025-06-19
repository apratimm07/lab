#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>  // for abs()
#include <dos.h>     // for delay()

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        putpixel(x1, y1, WHITE);
        delay(100); // slower for visibility

        if (x1 == x2 && y1 == y2)
            break;

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int x1 = 2, y1 = 3, x2 = 5, y2 = 5;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Scale points for visibility (optional)
    drawLineBresenham(x1 * 50, y1 * 50, x2 * 50, y2 * 50);

    getch();
    closegraph();
    return 0;
}
