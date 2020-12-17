#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

double delta(double x, double y) {
    return (x-y)*(double)(x-y);
}

class Point {
public:
    int x;
    int y;
    int z;
    Point(int x_=0, int y_=0, int z_=0): x(x_), y(y_),z (z_) {}
    friend ostream& operator << (ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << "," << p.z << ")";
        return os;
    }
    double distance_to(const Point& other) const {
        return sqrt(delta(x, other.x) + delta(y, other.y) + delta(z, other.z));
    }
};

class Vector {
public:
    static int glbidx;
    int idx;
    Point from;
    Point to;
    double dist;
    Vector(const Point& a, const Point& b) {
        idx = ++glbidx;
        from = a;
        to = b;
        dist = from.distance_to(to);
    }
    bool operator < (const Vector& other) {
        return dist == other.dist? idx < other.idx: dist > other.dist;
    }
    friend ostream& operator << (ostream& os, const Vector& v) {
        os << v.from << "-" << v.to << "=" <<fixed<<setprecision(2)<< v.dist;
        return os;
    }
};
int Vector::glbidx = 0;

int main() {
    int n; cin >> n;
    vector<Point> ps;
    for(int i=1; i<=n; i++) {
        int a, b, c; cin >> a >> b >> c;
        ps.push_back(Point(a, b, c));
    }
    vector<Vector> vs;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            vs.push_back(Vector(ps[i], ps[j]));
        }
    }
    sort(vs.begin(), vs.end());
    for(auto& item: vs) {
        cout << item << endl;
    }
    return 0;
}