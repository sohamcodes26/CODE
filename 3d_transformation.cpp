#include <iostream>
#include <cmath>
using namespace std;

// Function to translate the coordinates
void translate(int xcor[], int ycor[], int zcor[], int numVertices, int tx, int ty, int tz) {
    for (int i = 0; i < numVertices; i++) {
        xcor[i] += tx;
        ycor[i] += ty;
        zcor[i] += tz;
    }
    cout << "Coordinates after translation:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "(" << xcor[i] << ", " << ycor[i] << ", " << zcor[i] << ")\n";
    }
}

// Function to scale the coordinates
void scale(int xcor[], int ycor[], int zcor[], int numVertices, float sx, float sy, float sz) {
    for (int i = 0; i < numVertices; i++) {
        xcor[i] *= sx;
        ycor[i] *= sy;
        zcor[i] *= sz;
    }
    cout << "Coordinates after scaling:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "(" << xcor[i] << ", " << ycor[i] << ", " << zcor[i] << ")\n";
    }
}

// Function to rotate the coordinates
void rotate(int xcor[], int ycor[], int zcor[], int numVertices, char axis, float angle) {
    angle = angle * M_PI / 180.0; // Convert angle to radians
    for (int i = 0; i < numVertices; i++) {
        int tempX = xcor[i], tempY = ycor[i], tempZ = zcor[i];
        if (axis == 'x' || axis == 'X') {
            ycor[i] = tempY * cos(angle) - tempZ * sin(angle);
            zcor[i] = tempY * sin(angle) + tempZ * cos(angle);
        } else if (axis == 'y' || axis == 'Y') {
            xcor[i] = tempX * cos(angle) + tempZ * sin(angle);
            zcor[i] = -tempX * sin(angle) + tempZ * cos(angle);
        } else if (axis == 'z' || axis == 'Z') {
            xcor[i] = tempX * cos(angle) - tempY * sin(angle);
            ycor[i] = tempX * sin(angle) + tempY * cos(angle);
        }
    }
    cout << "Coordinates after rotation around " << axis << "-axis:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "(" << xcor[i] << ", " << ycor[i] << ", " << zcor[i] << ")\n";
    }
}

// Function to reflect the coordinates
void reflect(int xcor[], int ycor[], int zcor[], int numVertices) {
    int choice;
    cout << "Choose the plane/axis of reflection:\n";
    cout << "1. XY-plane\n2. YZ-plane\n3. ZX-plane\n4. Origin\n";
    cin >> choice;

    switch (choice) {
    case 1: // Reflect across XY-plane
        for (int i = 0; i < numVertices; i++) {
            zcor[i] *= -1;
        }
        break;
    case 2: // Reflect across YZ-plane
        for (int i = 0; i < numVertices; i++) {
            xcor[i] *= -1;
        }
        break;
    case 3: // Reflect across ZX-plane
        for (int i = 0; i < numVertices; i++) {
            ycor[i] *= -1;
        }
        break;
    case 4: // Reflect through the origin
        for (int i = 0; i < numVertices; i++) {
            xcor[i] *= -1;
            ycor[i] *= -1;
            zcor[i] *= -1;
        }
        break;
    default:
        cout << "Invalid choice!\n";
        return;
    }

    cout << "Coordinates after reflection:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "(" << xcor[i] << ", " << ycor[i] << ", " << zcor[i] << ")\n";
    }
}

// Function to shear the coordinates
void shear(int xcor[], int ycor[], int zcor[], int numVertices, float shxy, float shxz, float shyz) {
    for (int i = 0; i < numVertices; i++) {
        int newX = xcor[i] + shxy * ycor[i] + shxz * zcor[i];
        int newY = ycor[i] + shxy * xcor[i] + shyz * zcor[i];
        int newZ = zcor[i] + shxz * xcor[i] + shyz * ycor[i];
        xcor[i] = newX;
        ycor[i] = newY;
        zcor[i] = newZ;
    }

    cout << "Coordinates after shearing:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "(" << xcor[i] << ", " << ycor[i] << ", " << zcor[i] << ")\n";
    }
}

// Main function with menu-driven interface
int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    int xcor[numVertices], ycor[numVertices], zcor[numVertices];
    cout << "Enter the x, y, and z coordinates of the vertices:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i + 1 << ": ";
        cin >> xcor[i] >> ycor[i] >> zcor[i];
    }

    int choice;
    do {
        cout << "\nChoose a 3D transformation:\n";
        cout << "1. Translate\n2. Scale\n3. Rotate\n4. Reflect\n5. Shear\n6. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            int tx, ty, tz;
            cout << "Enter translation factors (tx, ty, tz): ";
            cin >> tx >> ty >> tz;
            translate(xcor, ycor, zcor, numVertices, tx, ty, tz);
            break;
        }
        case 2: {
            float sx, sy, sz;
            cout << "Enter scaling factors (sx, sy, sz): ";
            cin >> sx >> sy >> sz;
            scale(xcor, ycor, zcor, numVertices, sx, sy, sz);
            break;
        }
        case 3: {
            char axis;
            float angle;
            cout << "Enter the axis of rotation (x, y, z): ";
            cin >> axis;
            cout << "Enter the angle of rotation (in degrees): ";
            cin >> angle;
            rotate(xcor, ycor, zcor, numVertices, axis, angle);
            break;
        }
        case 4:
            reflect(xcor, ycor, zcor, numVertices);
            break;
        case 5: {
            float shxy, shxz, shyz;
            cout << "Enter shearing factors (shxy, shxz, shyz): ";
            cin >> shxy >> shxz >> shyz;
            shear(xcor, ycor, zcor, numVertices, shxy, shxz, shyz);
            break;
        }
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
