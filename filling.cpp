#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

class polygon_fill
{
    public:
    void drawshape(int xcor[], int ycor[], int numvertices)
    {
        for(int i=0; i<numvertices-1; i++)
        {
            line(xcor[i], ycor[i], xcor[i+1], ycor[i+1]);
        }
        line(xcor[0], ycor[0], xcor[numvertices-1], ycor[numvertices-1]);
    }

    void boundaryfill(int x, int y, int newcolor, int edgecolor)
    {
        int current = getpixel(x,y);
        if(current != newcolor && current != edgecolor)
        {
            putpixel(x,y,newcolor);
            boundaryfill(x+1,y,newcolor,edgecolor);
            boundaryfill(x,y+1,newcolor,edgecolor);
            boundaryfill(x-1,y,newcolor,edgecolor);
            boundaryfill(x,y-1,newcolor,edgecolor);
        }
    }

    void floodfill(int x, int y, int newcolor, int oldcolor)
    {
        int current = getpixel(x,y);
        if(current == oldcolor)
        {
            putpixel(x,y,newcolor);
            floodfill(x+1,y,newcolor,oldcolor);
            floodfill(x,y+1,newcolor,oldcolor);
            floodfill(x-1,y,newcolor,oldcolor);
            floodfill(x,y-1,newcolor,oldcolor);
        }
    }
};

int main()
{
    cout << "1.  BLACK         0\n"
     << "2.  BLUE          1\n"
     << "3.  GREEN         2\n"
     << "4.  CYAN          3\n"
     << "5.  RED           4\n"
     << "6.  MAGENTA       5\n"
     << "7.  BROWN         6\n"
     << "8.  LIGHTGRAY     7\n"
     << "9.  DARKGRAY      8\n"
     << "10. LIGHTBLUE     9\n"
     << "11. LIGHTGREEN   10\n"
     << "12. LIGHTCYAN    11\n"
     << "13. LIGHTRED     12\n"
     << "14. LIGHTMAGENTA 13\n"
     << "15. YELLOW       14\n"
     << "16. WHITE        15\n";


    int choice;
    cout<<"Choose algorithm: 1-Boundary Fill or 2-Flood Fill: \n";
    cin>>choice;

    int gd=DETECT, gm;
    initgraph(&gd,&gm, NULL);

    int numvertices;

    cout<<"Enter number of vertices of polygon: \n";
    cin>>numvertices;

    int xcor[numvertices], ycor[numvertices];

    for (int i = 0; i < numvertices; i++) 
    {
        cout << "Enter coordinates for vertex " << i + 1 << " (x, y): ";
        cin >> xcor[i] >> ycor[i];
    }


    polygon_fill ob;
    ob.drawshape(xcor,ycor,numvertices);

    if(choice==1)
    {
        int x,y,edgecolor, newcolor;
        cout<<"Enter any coordinates inside polygon: \n";
        cin>>x>>y;
        cout<<"Enter newcolor and edgecolor for boundary fill: \n";
        cin>>newcolor>>edgecolor;
        setcolor(edgecolor);
        ob.boundaryfill(x,y,newcolor,edgecolor);
    }
    else if(choice==2)
    {
        int x,y,oldcolor, newcolor;
        cout<<"Enter any coordinates inside polygon: \n";
        cin>>x>>y;
        cout<<"Enter newcolor and oldcolor for boundary fill: \n";
        cin>>newcolor>>oldcolor;
        ob.floodfill(x,y,newcolor,oldcolor);
    }
    else{cout<<"Wrong input: \n";}

    getch();
    closegraph();
    return 0;
}