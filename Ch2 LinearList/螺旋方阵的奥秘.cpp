#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

constexpr array<pair<int, int>, 4> adj_4 {{
    {0, 1}, {1, 0}, {0, -1}, {-1, 0} 
}};

int screw[30][30];

inline bool check_boundary(int x, int y, int size) {
    return (1 <= x && 1 <= y && x <= size && y <= size && screw[x][y] == 0);
}

inline void generate_screw(int size) {
    int cnt = 1, dir = 0;
    int x = 1, y = 1;
    while(true) {
        screw[x][y] = cnt++;
        if(cnt > size*size) break;
        int nx = x + adj_4[dir].first, ny = y + adj_4[dir].second;
        while(!check_boundary(nx, ny, size)) {
            dir = (dir + 1) % 4;
            nx = x + adj_4[dir].first, ny = y + adj_4[dir].second;
        }
        x = nx, y = ny;
    }
}

inline pair<int, int> find_in_screw(int size, int toFind) {
    for(size_t i=1; i<=size; i++)
        for(size_t j=1; j<=size; j++)
            if(screw[i][j] == toFind)
                return {i, j};
    return {-1, -1};
}

int main() {
    int n, m; cin >> n >> m;
    generate_screw(n);
    pair<int, int> ans = find_in_screw(n, m);
    cout << ans.first << " " << ans.second << '\n';
    return 0;
}