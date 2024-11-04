#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

const double PI = 3.14159265358979323846;

class Figure {
public:
    virtual int area() = 0;
    virtual int perimeter() = 0;
    virtual pair<int, int> mass() = 0;
};

class Rectangle : public Figure {
private:
    int a, b; // довжина, висота
    int x, y; // координати лівого верхнього кута
public:
    Rectangle(int a, int b, int x, int y) : a(a), b(b), x(x), y(y) {}

    int length() const { return a; }
    int height() const { return b; }

    int area() {
        return a * b;
    }

    int perimeter() {
        return 2 * a + 2 * b;
    }

    pair<int, int> mass() {
        int x_m = x + a / 2;
        int y_m = y - b / 2;
        return {x_m, y_m};
    }

    bool intersects(const Rectangle& other) const {
        return !(x + a <= other.x || other.x + other.a <= x ||
                 y <= other.y - other.b || other.y <= y - b);
    }
};

class Triangle : public Figure {
private:
    int angle1, angle2;
    int a; // основа
    int x, y; // ліва нижня координата
    int angle3 = 180 - angle1 - angle2; // обчислюємо третій кут

public:
    Triangle(int angle1, int angle2, int a, int x, int y) : angle1(angle1), angle2(angle2), a(a), x(x), y(y) {}

    int basis() const { return a; }

    int radian(int alfa) {
        return alfa * PI / 180;
    }

    int sideB() {
        return a * sin(radian(angle2)) / sin(radian(angle3));
    }

    int sideC() {
        return a * sin(radian(angle1)) / sin(radian(angle3));
    }

    int perimeter() {
        return a + sideB() + sideC();
    }

    int area() {
        return sqrt(perimeter() * (perimeter() - a) * (perimeter() - sideB()) * (perimeter() - sideC()));
    }

    pair<int, int> mass() {
        return {x + a / 3, y + sideB() * sin(radian(angle1)) / 3};
    }
};

class Ellipse : public Figure {
private:
    int x1, y1, x2, y2; // фокус1, фокус2
    int R, r;

public:
    Ellipse(int x1, int y1, int x2, int y2, int R, int r) : x1(x1), y1(y1), x2(x2), y2(y2), R(R), r(r) {}

    int biggerR() { return R; }
    int smallerR() { return r; }

    int perimeter() {
        return PI * (3 * (R + r) - sqrt((3 * R + r) * (R + 3 * r)));
    }

    int area() {
        return PI * r * R;
    }

    pair<int, int> mass() {
        double xCenter = (x1 + x2) / 2;
        double yCenter = (y1 + y2) / 2;
        return {xCenter, yCenter};
    }
};

pair<double, double> CommonMass(Figure* figures[], int numFigures) {
    double totalArea = 0;
    double xSum = 0, ySum = 0;

    for (int i = 0; i < numFigures; ++i) {
        double area = figures[i]->area();
        pair<double, double> center = figures[i]->mass();
        xSum += center.first * area;
        ySum += center.second * area;
        totalArea += area;
    }

    return {xSum / totalArea, ySum / totalArea};
}

int main() {
    Rectangle rectangle1(4, 2, 0, 4);
    Rectangle rectangle2(3, 3, 2, 5);
    Triangle triangle(60, 60, 5, 0, 0);
    Ellipse ellipse(0, 2, 3, 2, 5, 3);

    cout << "Rectangle 1:" << endl;
    cout << " Sides: a = " << rectangle1.length() << ", b = " << rectangle1.height() << endl;
    cout << " Area: " << rectangle1.area() << endl;
    cout << " Perimeter: " << rectangle1.perimeter() << endl;
    auto rectangle1Mass = rectangle1.mass();
    cout << " Mass center: (" << rectangle1Mass.first << ", " << rectangle1Mass.second << ")" << endl;

    cout << "Rectangle 2:" << endl;
    cout << " Sides: a = " << rectangle2.length() << ", b = " << rectangle2.height() << endl;
    cout << " Area: " << rectangle2.area() << endl;
    cout << " Perimeter: " << rectangle2.perimeter() << endl;
    auto rectangle2Mass = rectangle2.mass();
    cout << " Mass center: (" << rectangle2Mass.first << ", " << rectangle2Mass.second << ")" << endl;

    cout << "Triangle:" << endl;
    cout << " Sides: a = " << triangle.basis() << ", b = " << triangle.sideB() << ", c = " << triangle.sideC() << endl;
    cout << " Area: " << triangle.area() << endl;
    cout << " Perimeter: " << triangle.perimeter() << endl;
    auto triangleMass = triangle.mass();
    cout << " Mass center: (" << triangleMass.first << ", " << triangleMass.second << ")" << endl;

    cout << "Ellipse:" << endl;
    cout << " Radius: r=" << ellipse.smallerR() << ", R= " << ellipse.biggerR() << endl;
    cout << " Area: " << ellipse.area() << endl;
    cout << " Perimeter: " << ellipse.perimeter() << endl;
    auto ellipseMass = ellipse.mass();
    cout << " Mass center: (" << ellipseMass.first << ", " << ellipseMass.second << ")" << endl;


    // перевірка перетину
    if (rectangle1.intersects(rectangle2)) {
        cout << "Rectangles intersect." << endl;
    } else {
        cout << "Rectangles do not intersect." << endl;
    }

    Figure* figures[] = {&rectangle1, &rectangle2, &triangle, &ellipse};
    int numFigures = sizeof(figures) / sizeof(figures[0]);

    auto commonCenter = CommonMass(figures, numFigures);
    cout << "Common Mass Center: (" << commonCenter.first << ", " << commonCenter.second << ")" << endl;

    return 0;
}
