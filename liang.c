#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

// Modified cliptest function using pointers
int cliptest(float p, float q, float* u1, float* u2) {
    float r;
    if (p < 0.0) {
        r = q / p;
        if (r > *u2)
            return 0;
        else if (r > *u1)
            *u1 = r;
    }
    else if (p > 0.0) {
        r = q / p;
        if (r < *u1)
            return 0;
        else if (r < *u2)
            *u2 = r;
    }
    else if (q < 0.0)
        return 0;

    return 1;
}

// Liang-Barsky Line Clipping Function
void liangBarskyClip(float x0, float y0, float x1, float y1) {
    float dx = x1 - x0;
    float dy = y1 - y0;
    float u1 = 0.0, u2 = 1.0;

    if (cliptest(-dx, x0 - xmin, &u1, &u2))
        if (cliptest(dx, xmax - x0, &u1, &u2))
            if (cliptest(-dy, y0 - ymin, &u1, &u2))
                if (cliptest(dy, ymax - y0, &u1, &u2)) {
                    float nx0 = x0 + u1 * dx;
                    float ny0 = y0 + u1 * dy;
                    float nx1 = x0 + u2 * dx;
                    float ny1 = y0 + u2 * dy;

                    setcolor(WHITE);
                    line(nx0, ny0, nx1, ny1);
                }
}

// Function to draw each test case with label and line
void drawCase(const char* label, int x0, int y0, int x1, int y1) {
    cleardevice();

    // Draw clipping window
    setcolor(YELLOW);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line
    setcolor(RED);
    line(x0, y0, x1, y1);

    // Label
    setcolor(LIGHTBLUE);
    outtextxy(10, 10, (char*)label);
    getch();

    cleardevice();

    // Draw clipping window again
    setcolor(YELLOW);
    rectangle(xmin, ymin, xmax, ymax);

    setcolor(LIGHTBLUE);
    outtextxy(10, 10, (char*)label);
    liangBarskyClip(x0, y0, x1, y1);
    getch();
}

// Main driver
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Case 1: Line completely inside
    drawCase("Case 1: Line completely inside", 150, 150, 250, 250);

    // Case 2: Line completely outside
    drawCase("Case 2: Line completely outside", 50, 50, 70, 70);

    // Case 3: Line intersects one side
    drawCase("Case 3: Line intersects one side", 150, 50, 150, 150);

    // Case 4: Line intersects two sides
    drawCase("Case 4: Line intersects two sides", 50, 150, 350, 150);

    closegraph();
    return 0;
}