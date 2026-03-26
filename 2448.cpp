#include <iostream>
#include <algorithm>

using namespace std;

int n;
char board[8000][8000];

void fill_star(int x, int y){
    board[x][y] = '*';
    board[x+1][y-1] = '*';
    board[x+1][y+1] = '*';

    for(int i = y-2; i <= y+2; i++){
        board[x+2][i] = '*';
    }
}

void func(int s, int x, int y){
    if(s == 3){
        fill_star(x,y);
        return;
    }

    int ns = s/2;

    func(ns, x, y);
    func(ns, x+ns, y-ns);
    func(ns, x+ns, y+ns);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        fill(board[i], board[i] + n*2+2, ' ');
    }

    func(n,0,n-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n*2-1; j++){
            cout << board[i][j];
        }   
        cout << "\n";
    }

    return 0;
}