//26.03.06
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,h;
int board[102][102][102];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

vector<tuple<int,int,int>> arr;
queue<tuple<int,int,int>> q;


void bfs(){
    while(!q.empty()){
        auto [cx, cy, cz] = q.front(); q.pop();
        
        for(int i = 0; i < 6; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            if(board[nz][ny][nx] != 0) continue;
            board[nz][ny][nx] = board[cz][cy][cx]+1; 
            q.push({nx, ny, nz});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    
    for(int k = 0; k < h; k++){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                cin >> board[k][j][i];
                if(board[k][j][i] == 1) 
                    q.push({i,j,k});
            }   
        }
    }

    bfs();

    int ans = 0;

    for(int k = 0; k < h; k++){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(board[k][j][i]==0) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, board[k][j][i]);
            }   
        }
    }
    
    cout << ans-1;

    return 0;
}