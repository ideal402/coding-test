#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n,m;
int board[1000][1000];
int dist[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int,int>> q;

int main(){
    cin >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j]== 1){
                q.push({i, j});
                dist[i][j] = 0;
            }
            if(board[i][j]==0){
                dist[i][j] = -1;
            }
        }
    }

    while(!q.empty()){


        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    int ans = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            ans = max(dist[i][j], ans);
        }
    }

    cout << ans;

    return 0;
}