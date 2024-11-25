#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

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
        line(xcor[i]+centerX, centerY-ycor[i],xcor[i+1]+centerX, centerY-ycor[i+1]);
    }
    line(xcor[0] + centerX, centerY - ycor[0], xcor[numvertices - 1] + centerX, centerY -ycor[numvertices - 1]);
}

void translate(int xcor[], int ycor[], int numvertices, int tx, int ty)
{
    for(int i=0; i<numvertices; i++)
    {
        xcor[i] += tx;
        ycor[i] += ty;
    }

    cleardevice();
    drawAxis();
    drawShape(xcor, ycor, numvertices);
}

void scale(int xcor[], int ycor[],int numvertices, float sx, float sy)
{
    for(int i=0; i<numvertices; i++)
    {
        xcor[i] = sx*xcor[i];
        ycor[i] = sy*ycor[i];
    }

    cleardevice();
    drawAxis();
    drawShape(xcor, ycor, numvertices);
}

void rotate(int xcor[], int ycor[], int numvertices, int angle)
{
    int tempx[numvertices], tempy[numvertices];

    for(int i=0; i<numvertices; i++)
    {
        tempx[i] = xcor[i];
        tempy[i] = ycor[i];
    }

    for(int i=0; i<numvertices; i++)
    {
        xcor[i] = tempx[i]*cos(angle*3.14/180) - tempy[i]*sin(angle*3.14/180);
        
        ycor[i] = tempy[i]*cos(angle*3.14/180) + tempx[i]*sin(angle*3.14/180);
    }
    cleardevice();
    drawAxis();
    drawShape(xcor, ycor, numvertices);
}

void reflect(int xcor[], int ycor[], int numvertices )
{
    int choice;
    cout<<"\nSelect axis of reflection: \n1. X-axis\n2. Y-axis\n3. Origin\n4. y=x:";
    cin>>choice;

    switch(choice)
    {
        case 1:
        for(int i=0; i<numvertices; i++)
        {
            ycor[i] *= -1;
        }
        break;

        case 2:
        for(int i=0; i<numvertices; i++)
        {
            xcor[i] *= -1;
        }
        break;

        case 3:
        for(int i=0; i<numvertices; i++)
        {
            xcor[i] *= -1;
            ycor[i] *= -1;
        }
        break;

        case 4:
        for(int i=0; i<numvertices; i++)
        {
            swap(xcor[i],ycor[i]);
        }
        break;

        default:
        cout<<"Invalid input"<<endl;
        return;
    
    }
    cleardevice();
    drawAxis();
    drawShape(xcor, ycor, numvertices);
}

void shear(int xcor[], int ycor[], int numvertices, float shx, float shy)
{
    for(int i=0; i<numvertices; i++)
    {
        int newx = xcor[i];
        int newy = ycor[i];

        xcor[i] = newx + shx*newy;
        ycor[i] = newy + shy*newx;
    }
    cleardevice();
    drawAxis();
    drawShape(xcor, ycor, numvertices);
}

void displayMenu(int xcor[], int ycor[], int numvertices)
{
    int choice, repeat = 1;
while(repeat==1)
    {
    cout<<"Choose a 2D transformation: \n1. Translate\n2. Scale\n3. Rotate\n4. Reflect\n5. Shear\n";

    cin>>choice;
    
    switch(choice)
    {
        case 1:
        int tx, ty;
        cout<<"Enter tx and ty: \n";
        cin>>tx>>ty;
        translate(xcor,ycor,numvertices,tx,ty);
        break;

        case 2:
        float sx, sy;
        cout<<"Enter sx, sy: \n";
        cin>>sx>>sy;
        scale(xcor,ycor,numvertices,sx,sy);
        break;

        case 3:
        int angle;
        cout<<"Enter rotation angle: \n";
        cin>>angle;
        rotate(xcor, ycor, numvertices, angle);
        break;

        case 4:
        reflect(xcor, ycor, numvertices);
        break;

        case 5:
     float shx , shy;
        cout<<"Enter shx and shy: \n";
        cin>>shx>>shy;
        shear(xcor, ycor, numvertices, shx, shy);
        break;

        default:
        cout<<"Invalid input\n";
        return;
    }
    cout<<"Do you want to continue: Yes-1 or No-0\n";
    cin>>repeat;
    }
    
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, NULL);
    initwindow(1200, 800, "Resizable Graphics Window");
    drawAxis();
    int numvertices;
    cout<<"Enter number of vertices: \n";
    cin>>numvertices;

    int xcor[numvertices], ycor[numvertices];

    cout<<"Enter x and y coordinates: \n";
    for(int i=0; i<numvertices; i++)
    {
       cout<<"Vertex "<<i+1<<": ";
       cin>>xcor[i]>>ycor[i]; 
    }
    drawShape(xcor,ycor,numvertices);
    displayMenu(xcor, ycor, numvertices);

}