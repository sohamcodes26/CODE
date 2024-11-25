// 2) Implement Bresenhams line drawing algorithm for gentle slope line
// m<=1 i.e dx<=dy

#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;

class Bresenhams
{
    private:
    int x0, y0, x1, y1, p, dx, dy, x, y;

    public:
    void getpoints()
    {
        cout<<"Enter 1st point(left end): \n";
        cin>>x0>>y0;

        cout<<"Enter 2nd point: \n";
        cin>>x1>>y1;
    }

    void drawline()
    {
        dx = x1 - x0; 
        dy = y1 - y0;

        x = x0;
        y = y0;

        putpixel(x,y,WHITE);

        p = 2*dy - dx;

        while(x<=x1)
        {
            if(p<0)
            {
                x++;
                putpixel(x, y, WHITE);
                p = p + 2*dy;
                delay(1);
            }
            else
            {
                x++;
                y++;
                putpixel(x, y, WHITE);
                p = p + 2*dy - 2*dx;
                delay(1);
            }
        }
    }
};

int main()
{
    int gd = DETECT, gm=0;
    initgraph(&gd, &gm, NULL);

    Bresenhams ob;
    ob.getpoints();
    ob.drawline();

    getch();
    closegraph();
    return 0;
}