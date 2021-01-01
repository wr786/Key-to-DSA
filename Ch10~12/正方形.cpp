#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int n;

class Point {
public:
    int x, y;
    Point(int x_ = 0, int y_ = 0): x(x_), y(y_) {}
    bool operator == (const Point& other) const {
        return x == other.x && y == other.y;
    }
};

unordered_map<int, vector<Point> > dict;
vector<Point> ps;
int cnt;

inline void insert(const Point& p) {
    int key = p.x * p.x + p.y * p.y;
    if(dict.find(key) == dict.end()) {
        dict[key] = vector<Point>();
    }
    dict[key].push_back(p);
}

inline int search(const Point& p) {
    int key = p.x * p.x + p.y * p.y;
    if(dict.find(key) == dict.end()) {
        return 0;
    }
    for(auto& item: dict[key]) {
        if(p == item) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n && n) {
        cnt = 0;
        dict.clear();
        ps.clear();
        for(int i=1; i<=n; i++) {
            int x, y; cin >> x >> y;
            ps.push_back(Point(x, y));
            insert(ps.back());
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int x1 = ps[i].x, y1 = ps[i].y;
                int x2 = ps[j].x, y2 = ps[j].y;
                int dx = x2 - x1;
                int dy = y2 - y1;
                int x3 = x1 + dy, y3 = y1 - dx;
                int x4 = x2 + dy, y4 = y2 - dx;
                cnt += search(Point(x3, y3)) * search(Point(x4, y4));
                x3 = x1 - dy, y3 = y1 + dx;
                x4 = x2 - dy, y4 = y2 + dx;
                cnt += search(Point(x3, y3)) * search(Point(x4, y4));
            }
        }
        cout << cnt / 4 << endl;
    }   
}