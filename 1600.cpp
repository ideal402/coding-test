#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 50000

int n,m,k;
int board[204][204];
int visit[204][204][35];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dx2[] = {2,2,-2,-2,1,1,-1,-1};
int dy2[] = {1,-1,1,-1,2,-2,2,-2};

void bfs(){
    queue<tuple<int,int,int>> q;
    visit[0][0][k] = 1;
    q.push({0,0,k});

    while(!q.empty()){
        auto [cx, cy, cnt] = q.front();
        q.pop();

        if(cx == m-1 && cy == n-1) return;
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
         
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if(board[nx][ny] == 1) continue;
            if(visit[nx][ny][cnt] <= visit[cx][cy][cnt]+1) continue;

            visit[nx][ny][cnt] = visit[cx][cy][cnt] + 1;
            q.push({nx,ny,cnt});
        }

        if(cnt > 0){
            for(int i=0; i<8; i++){
                int nx = cx + dx2[i];
                int ny = cy + dy2[i];
            
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(board[nx][ny] == 1) continue;

                if(visit[nx][ny][cnt-1] <= visit[cx][cy][cnt]+1) continue;

                visit[nx][ny][cnt-1] = visit[cx][cy][cnt] + 1;
                q.push({nx,ny,cnt-1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n >> m;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            for(int x = k; x > -1; x--){         
                visit[i][j][x] = MAX;   
            }
        }   
    }

    bfs();

    int ans = MAX;

    for(int i = k; i > -1; i--){
        ans = min(ans, visit[m-1][n-1][i]);
    }

    if(ans == MAX){
        cout << -1;
    }
    else{
        cout << ans-1;
    }
    return 0;
}