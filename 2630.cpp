#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ans[2];
int board[130][130];

bool check(int x, int y, int size){
    int temp = board[x][y];

    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+size; ++j) {
            if(board[i][j] != temp) return false;        
        }
    }

    return true;
}

void cut(int x, int y,int size){

    if(check(x, y, size)){
        ans[board[x][y]] += 1;
        return;
    }

    for (int i = x; i < x+size; i += size/2) {
        for (int j = y; j < y+size; j += size/2) {
            cut(i, j, size/2);
        }   
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    cut(0,0,n);

    for(auto a: ans){
        cout << a << "\n";
    }


    return 0;
}