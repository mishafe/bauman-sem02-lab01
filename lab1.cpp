#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class point {
    float x;
    float y;
    point(double x, double y) {
        this->x = x;
        this->y = y;
    }
public:
    static point polar(float, float);
    static point offset_calc(point, int, int);
    float getx() { return x; };
    float gety() { return y; };
    point() { x = y = 0.0; }
};

point point::polar(float R, float F) {
    point p(R * cos(F), R * sin(F));
    return p;
}

point point::offset_calc(point a, int x_s, int y_s) {
    a.x -= x_s; // т.к смещение на СЗ
    a.y += y_s;
    return a;
}

int main(int argc, char* argv[]) {
    if (argc != 3) return -1;
    double rib, offset, x, y;
    sscanf(argv[1], "%le", &rib);
    sscanf(argv[2], "%le", &offset);
    x = y = offset / sqrt(2); // координаты центра треугольника
    const float pi = acos(-1);
    float angle = pi / 2;
    float R = rib / (2 * sin(pi / 3.0));
    point apex[3];
    int i = 0;
    while (i < 3) {
        apex[i] = point::polar(R, angle);
        apex[i] = point::offset_calc(apex[i], x, y);
        angle += 2 * pi / 3;
        i++;
    };
    cout << fixed;
    cout.precision(3);
    i = 0;
    while (i < 3) {
        cout << "(" << apex[i].getx() << "," << apex[i].gety() << ") " << endl;
        i++;
    }
    return 0;
}