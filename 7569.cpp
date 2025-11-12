#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

#define X first
#define Y second

using namespace std;

int board[102][102][102];
int visit[102][102][102];
int n, m, h;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int,int>> q;

void bfs(){
    while(!q.empty()){
        auto [cx, cy, cz] = q.front();
        q.pop();

        for(int i=0; i<6; i ++){

            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(visit[nx][ny][nz] != 0 || board[nx][ny][nz] == -1) continue;
            
            visit[nx][ny][nz] = visit[cx][cy][cz] + 1;
            
            q.push({nx, ny, nz});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for(int k = 0; k<h; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){
                    visit[i][j][k] = 1;
                    q.push({i,j,k});
                }
            }
        }
    }

    bfs();

    int ans = 0;

    for(int k = 0; k<h; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j][k] == 0 && visit[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, visit[i][j][k]);
            }
        }
    }

    cout << ans-1;

    return 0;
}