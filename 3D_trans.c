#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// Orthographic projection: simple simulation
void project3Dto2D(int x, int y, int z, int* xp, int* yp) {
    *xp = x + z / 2;
    *yp = y - z / 2;
}

void main() {
    int gd = DETECT, gm;

    int x1, y1, z1, x2, y2, z2, x3, y3, z3;
    int choice, tx, ty, tz, sx, sy, sz, angle;
    float rad;
    int x1n, y1n, z1n, x2n, y2n, z2n, x3n, y3n, z3n;
    int px1, py1, px2, py2, px3, py3;
    int ox1, oy1, ox2, oy2, ox3, oy3; // original projected coords

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    printf("Enter triangle coordinates (x1 y1 z1 x2 y2 z2 x3 y3 z3): ");
    scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);

    // Project original once
    project3Dto2D(x1, y1, z1, &ox1, &oy1);
    project3Dto2D(x2, y2, z2, &ox2, &oy2);
    project3Dto2D(x3, y3, z3, &ox3, &oy3);

    while (1) {
        cleardevice();

        // Draw original triangle (WHITE)
        setcolor(WHITE);
        line(ox1, oy1, ox2, oy2);
        line(ox2, oy2, ox3, oy3);
        line(ox3, oy3, ox1, oy1);

        printf("\n1. Translation\n2. Scaling\n3. Rotation (Z-axis)\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter tx, ty, tz: ");
                scanf("%d%d%d", &tx, &ty, &tz);
                x1n = x1 + tx; y1n = y1 + ty; z1n = z1 + tz;
                x2n = x2 + tx; y2n = y2 + ty; z2n = z2 + tz;
                x3n = x3 + tx; y3n = y3 + ty; z3n = z3 + tz;
                break;

            case 2:
                printf("Enter sx, sy, sz: ");
                scanf("%d%d%d", &sx, &sy, &sz);
                x1n = x1 * sx; y1n = y1 * sy; z1n = z1 * sz;
                x2n = x2 * sx; y2n = y2 * sy; z2n = z2 * sz;
                x3n = x3 * sx; y3n = y3 * sy; z3n = z3 * sz;
                break;

            case 3:
                printf("Enter angle (degrees): ");
                scanf("%d", &angle);
                rad = angle * 3.14159 / 180.0;

                x1n = x1 * cos(rad) - y1 * sin(rad);
                y1n = x1 * sin(rad) + y1 * cos(rad);
                z1n = z1;

                x2n = x2 * cos(rad) - y2 * sin(rad);
                y2n = x2 * sin(rad) + y2 * cos(rad);
                z2n = z2;

                x3n = x3 * cos(rad) - y3 * sin(rad);
                y3n = x3 * sin(rad) + y3 * cos(rad);
                z3n = z3;
                break;

            case 4:
                closegraph();
                exit(0);

            default:
                printf("Invalid choice!");
                getch();
                continue;
        }

        // Project transformed triangle
        project3Dto2D(x1n, y1n, z1n, &px1, &py1);
        project3Dto2D(x2n, y2n, z2n, &px2, &py2);
        project3Dto2D(x3n, y3n, z3n, &px3, &py3);

        // Draw transformed triangle in GREEN
        setcolor(GREEN);
        line(px1, py1, px2, py2);
        line(px2, py2, px3, py3);
        line(px3, py3, px1, py1);

        getch();
    }
}
