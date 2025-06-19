#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>  // For delay()

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1, y1, x2, y2, x3, y3;
    float fx1, fy1, fx2, fy2, fx3, fy3;
    int rx1, ry1, rx2, ry2, rx3, ry3;
    float angle, rad;
    int steps = 30;  // Animate from 0 to 30 degrees
    int i;

    // Original triangle points
    x1 = 100; y1 = 100;
    x2 = 150; y2 = 50;
    x3 = 200; y3 = 100;

    // Copy to float
    fx1 = x1; fy1 = y1;
    fx2 = x2; fy2 = y2;
    fx3 = x3; fy3 = y3;

    for (i = 0; i <= steps; i++) {
        cleardevice();

        angle = i;  // degrees
        rad = angle * 3.14159 / 180.0;  // convert to radians

        // Rotate all points about origin
        rx1 = fx1 * cos(rad) - fy1 * sin(rad);
        ry1 = fx1 * sin(rad) + fy1 * cos(rad);

        rx2 = fx2 * cos(rad) - fy2 * sin(rad);
        ry2 = fx2 * sin(rad) + fy2 * cos(rad);

        rx3 = fx3 * cos(rad) - fy3 * sin(rad);
        ry3 = fx3 * sin(rad) + fy3 * cos(rad);

        // Draw current rotated triangle
        line(rx1, ry1, rx2, ry2);
        line(rx2, ry2, rx3, ry3);
        line(rx3, ry3, rx1, ry1);

        delay(50);  // control animation speed
    }

    // Final triangle in RED
    setcolor(RED);
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx1, ry1);

    getch();
    closegraph();
    return 0;
}