#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int board[305][305];
int visit[304][304];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

// 빙산의 개수를 샌다
// 빙산의 개수가 2개 이상 -> 루프를 멈추고 출력
// 빙산의 개수가 1개면 -> 전체적으로 녹임과정 
// 반복

void bfs(int sx, int sy){
    queue<pair<int,int>> q;  
    visit[sx][sy] = 1;

    q.push({sx, sy});
    
    while(!q.empty()){
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || visit[nx][ny] != 0) continue;

            visit[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void melt(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visit[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(board[i][j] != 0){
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];  

                    if(ni<0 || ni >= n || nj<0 || nj >= m) continue;
                    
                    if(board[ni][nj] == 0) visit[i][j] -= 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] = visit[i][j] < 0 ? 0 : visit[i][j];
        }
    }
}

void reset_visit(){
    for (int i = 0; i < n; ++i) {
        fill(visit[i], visit[i]+m, 0);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    while(1){
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(board[i][j] != 0 && visit[i][j] ==0){
                    bfs(i,j);
                    cnt++;    
                }
            }
        }
        
        if(cnt > 1){
            cout << ans;
            return 0;
        }
        else if(cnt == 1){
            melt();
            reset_visit();
            ans++;
        }
        else{
            cout << 0;
            return 0;
        }
    }
}

