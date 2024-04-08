#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point &o) {
        return x == o.x && y == o.y;
    }
    bool operator!=(const Point &o) {
        return !(*this == o);
    }
    Point operator-(const Point &o) {
        return Point(x - o.x, y - o.y);
    }
    double length() const {
        return sqrt(1LL * x * x + 1LL * y * y);
    }
};

double distance(const Point &A, const Point &B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

long long dot(const Point &A, const Point &B) {
    return 1LL * A.x * B.x + 1LL * A.y * B.y;
}

double calcAngle(const Point &A, const Point &B) {
    return acos(dot(A, B) / A.length() / B.length());
}

vector<Point> convexHull(vector<Point> p, int n) {
    if (n <= 2) return p;

    for (int i = 1; i < p.size(); ++i) {
        if (p[0].x > p[i].x) swap(p[0], p[i]);
    }

    vector<Point> hull;
    hull.push_back(p[0]);

    do {
        Point P = hull.back();

        Point P0 = (hull.size() == 1 ? Point(P.x, P.y - 1) : hull[hull.size() - 2]);

        Point Q  = p[0];
        double angle = calcAngle(P0 - P, Q - P);

        for (int i = 1; i < n; ++i) {
            if (Q == P || Q == P0) {
                Q     = p[i];
                angle = calcAngle(P0 - P, Q - P);
                continue;
            }
            if (p[i] == P || p[i] == P0) continue;

            double newAngle = calcAngle(P0 - P, p[i] - P);

            if (abs(angle - newAngle) > EPS) {
                if (angle < newAngle) {
                    Q     = p[i];
                    angle = newAngle;
                }
            }
            else {
                if ((Q - P).length() > (p[i] - P).length()) {
                    Q     = p[i];
                    angle = newAngle;
                }
            }
        }
        hull.push_back(Q);
    } while (hull[0] != hull.back());

    hull.pop_back();

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

int main()
{
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