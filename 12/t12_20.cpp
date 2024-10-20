#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Point {
    int x, y;
    double m;
};

int read(const char *filename, Point points[], int max_points) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return -1;
    }

    int n = 0;

    while (n < max_points && file.peek() != EOF) {
        file.ignore(256, '[');
        file >> points[n].x;
        file.ignore(256, ',');
        file >> points[n].y;
        file.ignore(256, ',');
        file >> points[n].m;
        file.ignore(256, ']');
        n++;
    }

    file.close();
    return n;
}

void calculate(const Point points[], double levers[], int n) {
    for (int i = 0; i < n; i++) {
        levers[i] = points[i].m * (points[i].x + points[i].y);
    }
}

void findMax(const Point points[], const double levers[], int n, Point &first, Point &second, double &max_lever1, double &max_lever2) {
    max_lever1 = -1;
    max_lever2 = -1;

    for (int i = 0; i < n; i++) {
        if (levers[i] > max_lever1) {
            max_lever2 = max_lever1;
            second = first;
            max_lever1 = levers[i];
            first = points[i];
        } else if (levers[i] > max_lever2) {
            max_lever2 = levers[i];
            second = points[i];
        }
    }
}

int main() {
    const char *filename = "points.txt";
    Point points[1000];
    double levers[1000];

    int n = read(filename, points, 1000);
    if (n == -1) {
        return 1;
    }

    calculate(points, levers, n);

    Point first, second;
    double max_lever1, max_lever2;
    findMax(points, levers, n, first, second, max_lever1, max_lever2);

    cout << "The point with the greatest leverage: [" << first.x << ", " << first.y << ", " << first.m << "], lever: " << max_lever1 << endl;
    cout << "The point with the second largest leverage: [" << second.x << ", " << second.y << ", " << second.m << "], lever: " << max_lever2 << endl;

    return 0;
}
