// 6) Draw sine wave using bresenhams circle drawing algorithm

#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

// Function to draw the upper semicircle
void up_semicircle(int radius, int centerX, int centerY, int c) {
    int p; // Decision parameter
    int x = 0, y = radius;
    p = 3 - 2 * radius;

    while (x <= y) {
        putpixel(centerX + x, centerY - y, c); // Upper-right
        putpixel(centerX - x, centerY - y, c); // Upper-left
        putpixel(centerX + y, centerY - x, c); // Far-upper-right
        putpixel(centerX - y, centerY - x, c); // Far-upper-left

        if (p < 0) {
            x++;
            p = p + 4 * x + 6;
        } else {
            x++;
            y--;
            p = p + 4 * x - 4 * y + 10;
        }
    }
}

// Function to draw the lower semicircle
void down_semicircle(int radius, int centerX, int centerY, int c) {
    int p; // Decision parameter
    int x = 0, y = radius;
    p = 3 - 2 * radius;

    while (x <= y) {
        putpixel(centerX + x, centerY + y, c); // Lower-right
        putpixel(centerX - x, centerY + y, c); // Lower-left
        putpixel(centerX + y, centerY + x, c); // Far-lower-right
        putpixel(centerX - y, centerY + x, c); // Far-lower-left

        if (p < 0) {
            x++;
            p = p + 4 * x + 6;
        } else {
            x++;
            y--;
            p = p + 4 * x - 4 * y + 10;
        }
    }
}

// Main function
int main() {
    int gd = DETECT, gm;
    initwindow(1200,800,"BGI");
    setbkcolor(BLACK);
    cleardevice();

    int xc=200, yc=500, c=WHITE; //assuming sine wave starts from this coordinate i.e center co ordinate of 1st up_semicircle
    
    int wavelength,r, num_semicircle, total_length;
    cout<<"Enter wavelength of wave: \n";
    cin>>wavelength;
    cout<<"Enter total length of wave which should be multiple of wavelength: \n";
    cin>>total_length;
    r = wavelength/4;
    num_semicircle= total_length/(2*r);


    for(int i=0; i<num_semicircle; i++)
    {
        if(i%2==0)
        {
            up_semicircle(r,xc,yc,c);
        }
        else{
            down_semicircle(r,xc,yc,c);
        }
        xc = xc+2*r;
    }
    getch();
    closegraph();
    return 0;
}
