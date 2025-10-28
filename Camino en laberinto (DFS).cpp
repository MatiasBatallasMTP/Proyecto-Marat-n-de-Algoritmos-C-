#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<string>& maze, int r, int c) {
    return r>=0 && c>=0 && r<maze.size() && c<maze[0].size() && maze[r][c]!='#';
}

bool dfs(vector<string>& maze, int r, int c, int gr, int gc, vector<pair<int,int>>& path) {
    if (!isValid(maze, r, c)) return false;
    if (maze[r][c] == '*') return false;
    path.push_back({r,c});
    if (r==gr && c==gc) return true;
    maze[r][c] = '*';
    int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
    for (int i=0;i<4;++i)
        if (dfs(maze, r+dr[i], c+dc[i], gr, gc, path)) return true;
    path.pop_back();
    return false;
}

int main() {
    vector<string> maze = {
        "....#.",
        ".##..#",
        "......",
        ".#...."
    };
    vector<pair<int,int>> path;
    if (dfs(maze, 0,0,2,5, path)) {
        for (auto &p : path) cout << "("<<p.first<<","<<p.second<<") ";
        cout << endl;
    } else cout << "Sin camino\n";
}
