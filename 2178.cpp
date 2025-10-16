#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n,m;
int board[100][100];
bool visit[100][100];

int bfs(int s_x, int s_y){
    queue<pair<pair<int,int>, int>> q;
    pair<pair<int, int>, int> cur;
    pair<int, int> pos;

    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    int cur_cnt = 1;
    int n_x, n_y;

    visit[s_x][s_y] = true;
    q.push({{s_x, s_y}, cur_cnt});

    while(!q.empty()){
        cur = q.front();
        q.pop();
        
        pos = cur.X;
        cur_cnt = cur.Y;
        
        if(pos.X == n-1 && pos.Y == m-1){
            return cur_cnt;
        }

        for(int i=0; i<4; i++){
            n_x = pos.X + dx[i];
            n_y = pos.Y + dy[i];

            if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;
            if(visit[n_x][n_y] || board[n_x][n_y] == '0') continue;

            visit[n_x][n_y] = true;
            q.push({{n_x, n_y}, cur_cnt+1});
        }
    }

    return -1;
}

int main(){
    cin >> n >> m;
    string str;

    for(int i = 0; i<n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            board[i][j] = str[j];
            visit[i][j] = false;
        }
    }
    int ans = bfs(0,0);

    cout << ans;

    return 0;
}