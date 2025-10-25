#include <iostream>

using namespace std;

int n;
int board[22][22];
int board2[22][22];

void rotate(){
    int temp[22][22];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = board2[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board2[i][j] = temp[n-1-j][i];
        }
    }
}

void move(int dir){
    while (dir--)
    {
        rotate();
    }
    for(int i=0; i<n; i++){
        int pos = 0;
        int temp[21] = {};
        for(int j=0; j<n; j++){
            if(board2[i][j] == 0) continue;
            if(temp[pos] == 0){
                temp[pos] = board2[i][j];
            }
            else if(temp[pos] == board2[i][j]){
                temp[pos++] *= 2;
            }
            else{
                temp[++pos] = board2[i][j];
            }
        }
        for(int j=0; j<n; j++){
            board2[i][j] = temp[j];
        }
    }
}




int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    int mx = 0;

    for(int temp = 0; temp<1024; temp++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board2[i][j] = board[i][j];
            }
        }
        int brute = temp;
        for(int i=0; i<5; i++){
            int dir = brute %4;
            brute /= 4;
            move(dir);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mx = max(mx, board2[i][j]);
            }
        }
    }
    cout << mx;
}
