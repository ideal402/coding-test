#include <iostream>
#include <algorithm>

using namespace std;

int n;
int board[70][70];
string ans = "";

bool check(int x, int y, int n){
    int temp = board[x][y];

    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            if(temp != board[i][j]) return false;
        }
    }

    return true;
}

void quad(int x, int y, int n){
    if(check(x, y, n)){
        ans += board[x][y];
        return;
    }

    ans += "(";
    quad(x, y, n/2);
    quad(x, y+n/2, n/2);
    quad(x+n/2, y, n/2);
    quad(x+n/2, y+n/2, n/2);
    ans += ")";

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        string temp;

        cin >> temp;
        for(int j = 0; j < n; j++){
            board[i][j] = temp[j];
        }
    }

    quad(0,0, n);

    cout << ans;

    return 0;
}