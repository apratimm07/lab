// Program in C to draw a STAR 

#include<stdio.h>
#include<graphics.h>
  int main()
   {
    int gd = DETECT, gm ;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    setfillstyle(1,14);
    line(300,65,150,275);
    line(300,65,450,275);
    line(150,275,450,275);
    floodfill(305,105,15);

    line(150,145,300,360);
    line(150,145,450,145);
    line(300,360,450,145);
    floodfill(195,185,15);
    floodfill(395,185,15);
    floodfill(305,350,15);
    getch();
    return 0;
   }