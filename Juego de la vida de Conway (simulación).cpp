#include <iostream>
#include <vector>
using namespace std;

int countNeighbors(const vector<vector<int>>& board, int r, int c) {
    int dirs[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int count = 0;
    int R = board.size(), C = board[0].size();
    for (auto &d : dirs) {
        int nr = r + d[0], nc = c + d[1];
        if (nr>=0 && nc>=0 && nr<R && nc<C && board[nr][nc]==1)
            count++;
    }
    return count;
}

void nextGeneration(vector<vector<int>>& board) {
    vector<vector<int>> copy = board;
    int R = board.size(), C = board[0].size();
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++) {
            int live = countNeighbors(copy, i, j);
            if (copy[i][j] && (live < 2 || live > 3)) board[i][j] = 0;
            else if (!copy[i][j] && live == 3) board[i][j] = 1;
        }
}

int main() {
    vector<vector<int>> grid = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    cout << "Generacion inicial:\n";
    for (auto &r : grid) { for (int x : r) cout << x << " "; cout << endl; }

    nextGeneration(grid);

    cout << "\nSiguiente generacion:\n";
    for (auto &r : grid) { for (int x : r) cout << x << " "; cout << endl; }
}
