// #include <graphics.h>
// #include <conio.h>
// #include <math.h>
// #include <dos.h>  // for delay()

// int main() {
//     int gd = DETECT, gm;
//     int x1, y1, x2, y2, x3, y3;
//     float fx1, fy1, fx2, fy2, fx3, fy3;
//     float sx, sy, step, max_scale = 1.5;
//     int i, steps = 50;

//     initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

//     // Original triangle points
//     x1 = 100; y1 = 100;
//     x2 = 150; y2 = 50;
//     x3 = 200; y3 = 100;

//     // Store original as float
//     fx1 = x1; fy1 = y1;
//     fx2 = x2; fy2 = y2;
//     fx3 = x3; fy3 = y3;

//     for (i = 0; i <= steps; i++) {
//         cleardevice();

//         // Calculate current scaling factor
//         step = 1.0 + ((max_scale - 1.0) * i / steps);
//         sx = step;
//         sy = step;

//         // Scale points from origin (0,0)
//         int sx1 = fx1 * sx;
//         int sy1 = fy1 * sy;

//         int sx2 = fx2 * sx;
//         int sy2 = fy2 * sy;

//         int sx3 = fx3 * sx;
//         int sy3 = fy3 * sy;

//         // Draw scaled triangle
//         line(sx1, sy1, sx2, sy2);
//         line(sx2, sy2, sx3, sy3);
//         line(sx3, sy3, sx1, sy1);

//         delay(40);  // animation speed
//     }

//     // Final triangle in RED
//     setcolor(RED);
//     line(sx1, sy1, sx2, sy2);
//     line(sx2, sy2, sx3, sy3);
//     line(sx3, sy3, sx1, sy1);

//     getch();
//     closegraph();
//     return 0;
// }


#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>  // for delay()

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    float fx1, fy1, fx2, fy2, fx3, fy3;
    float sx, sy, step, max_scale = 1.5;
    int i, steps = 50;
    int sx1, sy1, sx2, sy2, sx3, sy3;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Original triangle points
    x1 = 100; y1 = 100;
    x2 = 150; y2 = 50;
    x3 = 200; y3 = 100;

    // Store original as float
    fx1 = x1; fy1 = y1;
    fx2 = x2; fy2 = y2;
    fx3 = x3; fy3 = y3;

    for (i = 0; i <= steps; i++) {
        cleardevice();

        // Calculate current scaling factor
        step = 1.0 + ((max_scale - 1.0) * i / steps);
        sx = step;
        sy = step;

        // Scale points from origin (0,0)
        sx1 = fx1 * sx;
        sy1 = fy1 * sy;

        sx2 = fx2 * sx;
        sy2 = fy2 * sy;

        sx3 = fx3 * sx;
        sy3 = fy3 * sy;

        // Draw scaled triangle
        line(sx1, sy1, sx2, sy2);
        line(sx2, sy2, sx3, sy3);
        line(sx3, sy3, sx1, sy1);

        delay(40);  // animation speed
    }

    // Final triangle in RED
    setcolor(RED);
    line(sx1, sy1, sx2, sy2);
    line(sx2, sy2, sx3, sy3);
    line(sx3, sy3, sx1, sy1);

    getch();
    closegraph();
    return 0;
}
