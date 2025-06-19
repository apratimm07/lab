// hut

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    rectangle(150, 200, 350, 350);

    
    line(150, 200, 250, 100);
    line(250, 100, 350, 200);
    line(150, 200, 350, 200);


    rectangle(225, 275, 275, 350);

    
    rectangle(170, 230, 210, 270);
    
    getch(); 
    closegraph(); 
    return 0;
}