#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2; 
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Không đủ điểm để tạo bao lồi\n";
        return vector<Point>();
    }

    vector<Point> hull;

    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x || (points[i].x == points[l].x && points[i].y < points[l].y)) {
            l = i;
        }
    }

    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != l);

    return hull;
}

double polygonArea(vector<Point>& points) {
    int n = points.size();
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }
    area = abs(area) / 2.0;
    return area;
}

int main() {
    vector<Point> points = {{4, 5}, {6, 4}, {7, 6}, {8, 7}, {9, 8}, {5, 10}, {4, 9}, {5, 9}, {8, 11}, {8, 5}};
    vector<Point> convexHullPoints = convexHull(points);
    double area = polygonArea(convexHullPoints);

    cout << "Bao lồi:\n";
    for (auto p : convexHullPoints) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    cout << "Diện tích: " << area << endl;

    return 0;
}
