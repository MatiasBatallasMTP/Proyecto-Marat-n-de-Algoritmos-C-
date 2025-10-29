#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell { int r, c, dist; };

int shortestPathBFS(vector<vector<int>>& grid, pair<int,int> start, pair<int,int> end) {
    int R = grid.size(), C = grid[0].size();
    vector<vector<int>> vis(R, vector<int>(C, 0));
    queue<Cell> q;
    q.push({start.first, start.second, 0});
    vis[start.first][start.second] = 1;
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.r == end.first && cur.c == end.second)
            return cur.dist;
        for (int i = 0; i < 4; ++i) {
            int nr = cur.r + dr[i], nc = cur.c + dc[i];
            if (nr>=0 && nc>=0 && nr<R && nc<C && grid[nr][nc]==0 && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                q.push({nr, nc, cur.dist+1});
            }
        }
    }
    return -1; // no hay camino
}

int main() {
    vector<vector<int>> grid = {
        {0,0,0,1},
        {1,0,1,0},
        {0,0,0,0},
        {1,1,0,0}
    };
    cout << "Distancia minima: " << shortestPathBFS(grid, {0,0}, {3,3}) << endl;
}
