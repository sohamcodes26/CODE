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
        
        drawline(x0,y0,x1,y1);

    }

    void drawline(int x0, int y0, int x1, int y1)
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
            // cout<<x<<","<<y<<endl;
        }

    }

    int centerX, centerY;

void drawAxis()
{
    int maxX, maxY;
    maxX = getmaxx();
    maxY = getmaxy();

    centerX = maxX/2;
    centerY = maxY/2;

    line(0,centerY, maxX, centerY);
    line(centerX, 0, centerX , maxY);
}

    void drawShape(int xcor[], int ycor[], int numvertices)
{
    for(int i=0; i < numvertices-1; i++)
    {
        drawline(xcor[i]+centerX, centerY-ycor[i],xcor[i+1]+centerX, centerY-ycor[i+1]);
    }
    drawline(xcor[0] + centerX, centerY - ycor[0], xcor[numvertices - 1] + centerX, centerY -ycor[numvertices - 1]);
}
};
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    DDA ob;
    // ob.getpoints();
    ob.drawAxis();
    int numvertices;
    cout<<"Enter numeber of vertices: \n";
    cin>>numvertices;

    int xcor[numvertices];
    int ycor[numvertices];

    cout<<"Enter coordinates one by one seperated by space: \n";
    for(int i=0; i<numvertices; i++)
    {
        cout<<"Coord no "<<i+1<<": ";
        cin>>xcor[i]>>ycor[i];
        cout<<endl;
    }

    
    ob.drawShape(xcor, ycor, numvertices);

    getch();
    closegraph();

    return 0;
}