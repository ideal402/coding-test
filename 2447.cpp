#include <iostream>
#include <algorithm>

using namespace std;

int n;
char board[7000][7000];

void star(int x, int y, int n){

    if(n == 1){
        board[x][y] = '*';
        return;
    }

    int next_n = n/3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i==1 && j==1) continue;
            star(x+i*next_n, y+j*next_n, next_n);
        }
    }

    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    


    cin >> n;

    for(int i = 0; i < n; i++){
        fill(board[i], board[i]+n, ' ');
    }

    star(0,0,n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}