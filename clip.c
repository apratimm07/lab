#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

void cohenSutherlandClip(int x0, int y0, int x1, int y1) {
    int code0 = computeCode(x0, y0);
    int code1 = computeCode(x1, y1);
    int accept = 0;

    while (1) {
        if ((code0 == 0) && (code1 == 0)) {
            accept = 1;
            break;
        }
        else if (code0 & code1) {
            break;
        }
        else {
            int code_out, x, y;
            if (code0 != 0) code_out = code0;
            else code_out = code1;

            if (code_out & TOP) {
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            }
            else if (code_out & BOTTOM) {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            }
            else if (code_out & RIGHT) {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }
            else if (code_out & LEFT) {
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            if (code_out == code0) {
                x0 = x;
                y0 = y;
                code0 = computeCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
        }
    }

    if (accept) {
        setcolor(WHITE);
        line(x0, y0, x1, y1);
    }
}

void drawCase(const char* label, int x0, int y0, int x1, int y1) {
    cleardevice();
    setcolor(YELLOW);
    rectangle(xmin, ymin, xmax, ymax);

    setcolor(RED);
    line(x0, y0, x1, y1);

    setcolor(LIGHTBLUE);
    outtextxy(10, 10, (char*)label);
    getch();

    cleardevice();
    setcolor(YELLOW);
    rectangle(xmin, ymin, xmax, ymax);

    setcolor(LIGHTBLUE);
    outtextxy(10, 10, (char*)label);
    cohenSutherlandClip(x0, y0, x1, y1);
    getch();
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // 1. Inside
    drawCase("Case 1: Line completely inside", 150, 150, 250, 250);

    // 2. Outside
    drawCase("Case 2: Line completely outside", 50, 50, 70, 70);

    // 3. One side intersect
    drawCase("Case 3: Line intersects one side", 150, 50, 150, 150);

    // 4. Two sides intersect
    drawCase("Case 4: Line intersects two sides", 50, 150, 350, 150);

    closegraph();
    return 0;
}
