#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

class midcircle
{
    private:
    int xc, yc, r, s, x, y;

    public:
    
    void getinput()
    {
        cout<<"Enter xc, yc: \n";
        cin>>xc>>yc;
        cout<<"Enter radius: \n";
        cin>>r;
    }

    void drawcircle(int xc,int yc, int r, int c)
    {
        x = 0;
        y = r;
        putpixel(x,y,WHITE);

        s = 1-r;

        while(x<=y)
        {
           // putpixel(xc+x, yc+y, WHITE);
            putpixel(xc+x, yc-y,c);
            // putpixel(xc-x, yc+y,c);
            putpixel(xc-x, yc-y, c);

          //  putpixel(xc+y, yc+x, WHITE);
            putpixel(xc+y, yc-x,c);
            // putpixel(xc-y, yc+x,c);
            putpixel(xc-y, yc-x, c);
            

            if(s<0)
            {
                x++;
                s += 2*x +1;
            }
            else{
                x++;
                y--;
                s += 2*x - 2*y + 1;
            }

        }
    }
};

int main()
{
    int gd = DETECT, gm, r;
    initgraph(&gd, &gm, NULL);

    midcircle ob;
    cout<<"Enter the largest radius of rainbow: \n";
    cin>>r;
    int xc, yc;
    cout<<"Enter the center point for rainbow: \n";
    cin>>xc>>yc;

    int c[7] = {COLOR(148, 0, 211),   // Violet (RGB)
                COLOR(75, 0, 130),    // Indigo (RGB)
                COLOR(0, 0, 255),     // Blue
                COLOR(0, 255, 0),     // Green
                COLOR(255, 255, 0),   // Yellow
                COLOR(255, 165, 0),   // Orange
                COLOR(255, 0, 0) };   // Red

    for(int i=0; i<7; i++)
    {
        ob.drawcircle(xc, yc, r-i*20 , c[i]);
    }

    getch();
    closegraph();
    return 0;
}