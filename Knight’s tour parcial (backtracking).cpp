#include <iostream>
#include <vector>
using namespace std;

int N = 5;
int movesX[8] = {2,1,-1,-2,-2,-1,1,2};
int movesY[8] = {1,2,2,1,-1,-2,-2,-1};

bool isValid(int x, int y, vector<vector<int>>& sol) {
    return (x>=0 && y>=0 && x<N && y<N && sol[x][y]==-1);
}

bool knightTour(int x, int y, int movei, vector<vector<int>>& sol) {
    if (movei == N*N) return true;
    for (int k=0;k<8;k++) {
        int nx = x + movesX[k];
        int ny = y + movesY[k];
        if (isValid(nx, ny, sol)) {
            sol[nx][ny] = movei;
            if (knightTour(nx, ny, movei+1, sol)) return true;
            sol[nx][ny] = -1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> sol(N, vector<int>(N, -1));
    sol[0][0] = 0;
    knightTour(0, 0, 1, sol);
    for (auto &r : sol) {
        for (int v : r) cout << v << "\t";
        cout << endl;
    }
}
