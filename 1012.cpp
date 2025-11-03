#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[52][52];
int visit[52][52];
int cnt, t, m, n, k, x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    visit[x][y] = 1;
    q.push({x, y});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int cx = cur.X, cy = cur.Y;

        for(int i=0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny] == 1 || board[nx][ny] == 0) continue;

            visit[nx][ny] = 1;
            q.push({nx, ny});
        } 
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    
    for(int time = 0; time < t; time++){
        
        cin >> m >> n >> k;

        for(int i=0; i<n; i++){
            fill(board[i], board[i]+m, 0);
            fill(visit[i], visit[i]+m, 0);
        }

        for(int i=0; i<k; i++){
            cin >> x >> y;
            board[y][x] = 1;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visit[i][j] == 0 && board[i][j] == 1){
                    bfs(i, j);
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }


    return 0;
}