// concentric circles

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int x = 250, y = 200;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 

    circle(x, y, 50);  
    circle(x, y, 80);  
    circle(x, y, 110); 

    getch(); 
    closegraph(); 
    return 0;
}