#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int mx = 3*3*3*3*3*3*3;
int n;
int board[mx+3][mx+3];
int ans[3];


bool check(int x, int y, int size){
    int init = board[x][y];

    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+size; j++){
            if(board[i][j] != init) return false;
        }
    }

    return true;
}

void cut(int x, int y, int size){
    if(check(x, y, size)){
        ans[board[x][y]+1]++;
        return;
    }

    for (int i = x; i < x + size; i += size/3) {
        for (int j = y; j < y+size; j += size/3) {
            cut(i, j, size/3);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    cut(0,0,n);

    for(int x: ans){
        cout << x << "\n";
    }

    return 0;
}