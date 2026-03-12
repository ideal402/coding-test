#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


//1. 대륙을 구분한다.
//2. 다리를 놓는다.(bfs)

int n;
int cnt = 1;
int board[105][105];
int visit[105][105];
int b[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    visit[sx][sy] = cnt;
    q.push({sx, sy});

    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == 0 || visit[nx][ny] != 0) continue;

            visit[nx][ny] = cnt;
            q.push({nx, ny}); 
        }
    }
}

int check(int num){
    queue<pair<int, int>> q; 
    int ans = 1000;
    int count = 2;

    for (int i = 0; i < n; ++i) {
        fill(b[i], b[i] + n, 0);    
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(visit[i][j] == num){
                 for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(b[nx][ny] == 1 || visit[nx][ny] != 0) continue;

                    b[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            };
        }
    }

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if(visit[nx][ny] > 0) {
                if(visit[nx][ny] != num){
                    ans = min(b[cx][cy], ans);
                }
                continue;
            };

            if(b[nx][ny] != 0) continue;
            

            b[nx][ny] = b[cx][cy] + 1;
            q.emplace(nx, ny);
        }
    }
    
    return ans;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dis = 10000;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(board[i][j] == 1 && visit[i][j] == 0){
                bfs(i, j);
                cnt++;
            } 
        }
    }

    for (int i = 1; i < cnt; ++i) {
        dis = min(dis, check(i));
    }

    cout << dis;

    return 0;
}