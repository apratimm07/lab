#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>  // Required for delay()

// Function to implement DDA algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1, y = y1;

    int i; // Declare i outside the loop for Turbo C compatibility
    for (i = 0; i <= steps; i++) {
        putpixel((int)x, (int)y, WHITE);  // Plot pixel
        x += xIncrement;
        y += yIncrement;
        delay(10);  // Small delay to visualize drawing
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for coordinates
    printf("Enter the starting coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending coordinates (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw user-defined line
    drawLineDDA(x1, y1, x2, y2);

    getch();  // Wait for user input
    closegraph();
    return 0;
}
