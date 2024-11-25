// 3) Implement Midpoint circle drawing algorithm

#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

void drawcircle(int radius, int centerX, int centerY)
{
    int p; //decision paraameter
    int x=0, y=radius;
    putpixel(x,y,WHITE);
    p = 1 - radius;

    while(x<=y)
    {
        putpixel(centerX+x, centerY+y,WHITE);
        putpixel(centerX-x, centerY+y,WHITE);
        putpixel(centerX+x, centerY-y,WHITE);
        putpixel(centerX-x, centerY-y,WHITE);
        
        putpixel(centerX+y, centerY+x,WHITE);
        putpixel(centerX-y, centerY+x,WHITE);
        putpixel(centerX+y, centerY-x,WHITE);
        putpixel(centerX-y, centerY-x,WHITE);
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
    initgraph(&gd,&gm, NULL);

    int radius, centerX, centerY;
    cout<<"Enter center of circle: \n";
    cin>>centerX>>centerY;

    cout<<"Enter radius of circle: \n";
    cin>>radius;

    drawcircle(radius, centerX, centerY);
    getch();
    closegraph();
    return 0;

}   