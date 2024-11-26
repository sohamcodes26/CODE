#include <iostream>
#include <graphics.h>
using namespace std;

struct Point {
    int x, y;
};

int xmin, ymin, xmax, ymax;

// Check if a point is inside the clipping boundary
bool isInside(Point p, int edge) {
    switch (edge) {
        case 0: return p.x >= xmin; // Left
        case 1: return p.x <= xmax; // Right
        case 2: return p.y >= ymin; // Bottom
        case 3: return p.y <= ymax; // Top
    }
    return false;
}

// Find the intersection of a line segment with the clipping boundary
Point getIntersection(Point p1, Point p2, int edge) {
    Point intersection;
    float m = (float)(p2.y - p1.y) / (p2.x - p1.x);

    switch (edge) {
        case 0: // Left
            intersection.x = xmin;
            intersection.y = p1.y + m * (xmin - p1.x);
            break;
        case 1: // Right
            intersection.x = xmax;
            intersection.y = p1.y + m * (xmax - p1.x);
            break;
        case 2: // Bottom
            intersection.y = ymin;
            intersection.x = p1.x + (ymin - p1.y) / m;
            break;
        case 3: // Top
            intersection.y = ymax;
            intersection.x = p1.x + (ymax - p1.y) / m;
            break;
    }
    return intersection;
}

// Clip the polygon against a single edge
int clipPolygon(Point polygon[], int n, Point clipped[], int edge) {
    int newCount = 0;

    for (int i = 0; i < n; i++) {
        Point current = polygon[i];
        Point next = polygon[(i + 1) % n];

        bool currInside = isInside(current, edge);
        bool nextInside = isInside(next, edge);

        if (currInside && nextInside) {
            clipped[newCount++] = next;
        } else if (currInside && !nextInside) {
            clipped[newCount++] = getIntersection(current, next, edge);
        } else if (!currInside && nextInside) {
            clipped[newCount++] = getIntersection(current, next, edge);
            clipped[newCount++] = next;
        }
    }
    return newCount;
}

int main() {
    int gd = DETECT, gm;
    initwindow(800,800,"j");

    cout << "Enter the coordinates of the clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    rectangle(xmin, ymin, xmax, ymax);

    int n;
    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;

    Point polygon[20], clipped[20];
    cout << "Enter the vertices of the polygon (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    // Draw the original polygon
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % n].x, polygon[(i + 1) % n].y);
    }

    // Clip the polygon against all edges
    int clippedSize = n;
    for (int edge = 0; edge < 4; edge++) {
        clippedSize = clipPolygon(polygon, clippedSize, clipped, edge);
        for (int i = 0; i < clippedSize; i++) {
            polygon[i] = clipped[i];
        }
    }

    // Draw the clipped polygon
    setcolor(GREEN);
    for (int i = 0; i < clippedSize; i++) {
        line(clipped[i].x, clipped[i].y, clipped[(i + 1) % clippedSize].x, clipped[(i + 1) % clippedSize].y);
    }

    getch();
    closegraph();
    return 0;
}
