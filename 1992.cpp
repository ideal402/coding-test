#include <iostream>
#include <algorithm>

using namespace std;

int n;
int board[70][70];
string ans = "";

bool check(int x, int y, int size){
    int temp = board[x][y];

    for (int i = x; i<x+size; ++i) {
        for (int j = y; j<y+size; ++j) {
            if(board[i][j] != temp) return false;
        }
    }
    return true;
}

void cut(int x, int y, int size){

    if(check(x,y,size)){
        ans += board[x][y];
        return;
    }

    ans += "(";

    for (int i = x; i < x+size; i+=size/2) {
        for (int j = y; j < y+size; j+=size/2) {
            cut(i, j, size/2);
        }
    }
    ans += ")";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string temp;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        for (int j = 0; j < n; ++j) {
            board[i][j] = temp[j];
        }
    }

    cut(0,0,n);


    cout << ans;
    return 0;
}