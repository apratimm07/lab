#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int choice, tx, ty, sx, sy, angle;
    float radian;
    int x1n, y1n, x2n, y2n, x3n, y3n;
    
    initgraph(&gd, &gm, "C://turboc3/bgi");
    
    printf("Enter triangle coordinates (x1 y1 x2 y2 x3 y3): ");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    cleardevice();
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    
    while(1) {
        cleardevice();
        printf("\n1. Translation\n2. Scaling\n3. Rotation\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        cleardevice();
        setcolor(WHITE);
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
        
        switch(choice) {
            case 1:  // Translation
                printf("Enter translation factors (tx ty): ");
                scanf("%d%d", &tx, &ty);
                setcolor(YELLOW);
                line(x1+tx, y1+ty, x2+tx, y2+ty);
                line(x2+tx, y2+ty, x3+tx, y3+ty);
                line(x3+tx, y3+ty, x1+tx, y1+ty);
                break;
                
            case 2:  // Scaling
                printf("Enter scaling factors (sx sy): ");
                scanf("%d%d", &sx, &sy);
                setcolor(LIGHTBLUE);
                line(x1*sx, y1*sy, x2*sx, y2*sy);
                line(x2*sx, y2*sy, x3*sx, y3*sy);
                line(x3*sx, y3*sy, x1*sx, y1*sy);
                break;
                
            case 3:  // Rotation
                printf("Enter rotation angle (degrees): ");
                scanf("%d", &angle);
                radian = angle * (3.14159265/180);
                
                x1n = x1*cos(radian) - y1*sin(radian);
                y1n = x1*sin(radian) + y1*cos(radian);
                x2n = x2*cos(radian) - y2*sin(radian);
                y2n = x2*sin(radian) + y2*cos(radian);
                x3n = x3*cos(radian) - y3*sin(radian);
                y3n = x3*sin(radian) + y3*cos(radian);
                
                setcolor(LIGHTGREEN);
                line(x1n, y1n, x2n, y2n);
                line(x2n, y2n, x3n, y3n);
                line(x3n, y3n, x1n, y1n);
                break;
                
            case 4:
                closegraph();
                exit(0);
                
            default:
                printf("Invalid choice!");
        }
        getch();
    }
}