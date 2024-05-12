#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double distance(const Point &A, const Point &B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool ccw(const Point &A, const Point &B, const Point &C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (C.x - A.x) * (B.y - A.y) > 0;
}

vector<Point> convexHull(vector<Point> p, int n) {
    sort(p.begin(), p.end(), [](const Point &A, const Point &B) {
        if (A.x != B.x) return A.x < B.x;
        return A.y < B.y;
    });

    vector<Point> hull;
    hull.push_back(p[0]);

    for (int i = 1; i < n; ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i])) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i])) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    if (n > 1) hull.pop_back();

    return hull;
}

double polygonArea(const vector<Point> &polygon) {
    double area = 0.0;
    int n = polygon.size();

    for (int i = 0; i < n; ++i) {
        area += (polygon[i].x * polygon[(i + 1) % n].y - polygon[(i + 1) % n].x * polygon[i].y);
    }

    return abs(area) / 2.0;
}

double closestPairDistance(const vector<Point> &points) {
    int n = points.size();
    double minDistance = numeric_limits<double>::infinity();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }
    return minDistance;
}


int main() {
    int n = 15;
    // cin >> n;
    vector<Point> p(n);
    // for (Point &a : p) {
    //     cout << "point\n";
    //     cin >> a.x >> a.y;
    // }

    p[0].x = 3;
    p[0].y = 5;

    p[1].x = -1;
    p[1].y = 8;
    
    p[2].x = 6;
    p[2].y = 2;

    p[3].x = 0;
    p[3].y = 0;

    p[4].x = -2;
    p[4].y = -3;

    p[5].x = 7;
    p[5].y = 4;

    p[6].x = 2;
    p[6].y = 9;

    p[7].x = 4;
    p[7].y = -1;

    p[8].x = -5;
    p[8].y = 6;

    p[9].x = 1;
    p[9].y = -4;

    p[10].x = 9;
    p[10].y = 0;

    p[11].x = -3;
    p[11].y = 2;

    p[12].x = 8;
    p[12].y = 7;

    p[13].x = -6;
    p[13].y = -2;

    p[14].x = 5;
    p[14].y = -5;

    for (Point &a : p) {
        cout << "point : ";
        cout << a.x << ' ' << a.y << '\n';
    }
    
    vector<Point> hull = convexHull(p, n);

    cout << "So diem bao loi: " << hull.size() << '\n';
    cout << "Output: " << endl;
    for (Point p : hull) {
        cout << p.x << ' ' << p.y << '\n';
    }

    double hullArea = polygonArea(hull);
    cout << "Dien tich bao loi': " << hullArea << endl;

    double minDist = closestPairDistance(p);
    cout << "Khoang cach nho nhat giua cac diem trong tap hop: " << minDist << endl;

    return 0;
}