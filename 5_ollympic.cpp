//5) Draw olympic ring using any one of circle drawing algorithm

#include<iostream>
#include<graphics.h>
using namespace std;

void drawCircle( int xc, int yc,int radius, int color)
{
    int x=0, y=radius;
    
    int p = 1-radius;

    while(x<=y)
    {
        putpixel(xc+x, yc+y, color);
        putpixel(xc+x, yc-y, color);
        putpixel(xc-x, yc+y, color);
        putpixel(xc-x, yc-y, color);

        putpixel(xc+y, yc+x, color);
        putpixel(xc+y, yc-x, color);
        putpixel(xc-y, yc+x, color);
        putpixel(xc-y, yc-x, color);

        if(p<0)
        {
            x++;
            p = p + 2*x + 1;
        }
        else
        {
            x++;
            y--;
            p = p + 2*x - 2*y + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,NULL);
    setbkcolor(WHITE);
    cleardevice();

    int radius = 50;
    // Draw Olympic rings with respective colors
    drawCircle(200, 150, radius, BLUE);    // Blue ring (Top left)
    drawCircle(300, 150, radius, BLACK);   // Black ring (Top center)
    drawCircle(400, 150, radius, RED);     // Red ring (Top right)
    drawCircle(250, 200, radius, YELLOW);  // Yellow ring (Bottom left)
    drawCircle(350, 200, radius, GREEN);   // Green ring (Bottom right)

    getch();
    closegraph();
    return 0;
}