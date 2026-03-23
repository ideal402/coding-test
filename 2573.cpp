#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int board[304][304];
int visit[304][304];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }   
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0) {

                for(int k = 0; k < 4; k++){
                    int n_i = i+dx[i];
                    int n_j = j+dy[i];
                    
                }
            }
        }   
    }


    return 0;
}