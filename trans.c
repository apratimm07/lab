#include <graphics.h>
#include <conio.h>
#include <dos.h>  // for delay()

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int tx, ty, steps, i;
    float dx, dy;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Original triangle coordinates
    x1 = 100; y1 = 100;
    x2 = 150; y2 = 50;
    x3 = 200; y3 = 100;

    // Translation distance
    tx = 50;
    ty = 30;

    // Number of animation steps
    steps = 50;

    // Calculate small step movements
    dx = (float)tx / steps;
    dy = (float)ty / steps;

    for (i = 0; i <= steps; i++) {
        cleardevice();

        // Draw current triangle position
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);

        delay(30);  // adjust speed

        // Move triangle slightly
        x1 += dx; y1 += dy;
        x2 += dx; y2 += dy;
        x3 += dx; y3 += dy;
    }

    // Final triangle in RED
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}
