#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>

// Function to draw 8 symmetrical points
void drawCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void bresenhamCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y) {
        drawCirclePoints(xc, yc, x, y);
        delay(20); // Add delay to visualize drawing
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter center of circle (x y): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius of circle: ");
    scanf("%d", &r);

    bresenhamCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
