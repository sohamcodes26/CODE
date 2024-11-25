#include <iostream>
#include <graphics.h>

using namespace std;

// Region codes for Cohen-Sutherland algorithm
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Function to compute region code for a point
int computeRegionCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

// Cohen-Sutherland Line Clipping Algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int code1 = computeRegionCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeRegionCode(x2, y2, xmin, ymin, xmax, ymax);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints are inside the clipping window
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints share an outside region, so the line is outside
            break;
        } else {
            // Calculate the intersection point
            int codeOut;
            float x, y;

            // Pick the outside point
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            // Find intersection point using slope-intercept formula
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
                cout<<"1:"<<x<<","<<y;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
                cout<<"2:"<<x<<","<<y;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
                cout<<"3:"<<x<<","<<y;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
                cout<<"4:"<<x<<","<<y;
            }

            // Replace outside point with intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2); // Draw the clipped line
    } else {
        cout << "Line is outside the clipping window.\n";
    }
}

int main() {
    int gd = DETECT, gm;
    initwindow(800,800,"hi");


    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the line (x1, y1, x2, y2):\n";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    int xmin, ymin, xmax, ymax;
    cout << "Enter the coordinates of the clipping window (xmin, ymin, xmax, ymax):\n";
    cin >> xmin >> ymin >> xmax >> ymax;

    // Draw the clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Perform line clipping
    cohenSutherlandClip(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}
