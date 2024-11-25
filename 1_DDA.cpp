//1) Implement DDA line drawing algorithm for Sharp slope and steep slope line

#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;

class DDA
{
    private:
    int x0, y0, x1, y1, dx, dy, steps;
    double x, y, x_inc, y_inc;

    public:
    void getpoints()
    {
        cout<<"Enter 1st point: \n";
        cin>>x0>>y0;

        cout<<"Enter 2nd point: \n";
        cin>>x1>>y1;
    }

    void drawline()
    {
        dx = x1 - x0;
        dy = y1 - y0;

        if(abs(dx)>abs(dy))
        {
            steps= abs(dx);
        }
        else
        {
            steps = abs(dy);
        }

        x = abs(x0);
        y = abs(y0);
        putpixel(round(x),round(y), WHITE);

        x_inc = (float)dx/steps;
        y_inc = (float)dy/steps;

        for(int i=0; i<steps; i++)
        {
            x += x_inc;
            y += y_inc;

            putpixel(round(x),round(y), WHITE);
            delay(3);
            cout<<x<<","<<y<<endl;
        }

    }
};
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    DDA ob;
    ob.getpoints();
    ob.drawline();

    getch();
    closegraph();

    return 0;
}