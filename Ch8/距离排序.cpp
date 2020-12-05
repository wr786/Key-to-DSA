#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#define EPS 1e-6
using namespace std;

double delta2(double a, double b) {
    return (a-b)*(a-b);
}

class Point {
private:
    double x;
    double y;
    double z;
public:
    Point(double x_=0, double y_=0, double z_=0): x(x_), y(y_), z(z_) {}
    Point(const Point& other): x(other.x), y(other.y), z(other.z) {}
    double distance_to(const Point& other) const {
        return sqrt(delta2(x, other.x) + delta2(y, other.y) + delta2(z, other.z));
    }
    friend istream& operator>> (istream& is, Point& p) {
        is >> p.x >> p.y >> p.z;
        return is;
    }
    friend ostream& operator<< (ostream& os, const Point& p) {
        os << "(" << (int)p.x << "," << (int)p.y << "," << (int)p.z << ")";
        return os;
    }
};

class Vector {
private:
    static int totVecCnt;
    int idx;
    Point fromPos;
    Point toPos;
    double norm;
public:
    Vector(const Point& f, const Point& t): fromPos(f), toPos(t) {
        norm = f.distance_to(t);
        idx = ++totVecCnt;
    }
    friend ostream& operator<< (ostream& os, const Vector& v) {
        os << v.fromPos << "-" << v.toPos << "=" << fixed << setprecision(2) << v.norm;
        return os;
    }
    bool operator < (const Vector& other) const {
        return fabs(norm - other.norm) < EPS? idx < other.idx: norm > other.norm;
    }
};
int Vector::totVecCnt = 0;

int main() {
    int n; cin >> n;
    vector<Point> points;
    for(int i=1; i<=n; i++) {
        Point* tmp = new Point;
        cin >> *tmp;
        points.push_back(*tmp);
    }
    vector<Vector> vectors;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            vectors.push_back(Vector(points[i], points[j]));
        }
    }
    sort(vectors.begin(), vectors.end());
    for(auto it = vectors.begin(); it != vectors.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}