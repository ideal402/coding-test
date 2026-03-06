#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int board[302][302];
int n, l;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};


int bfs(int sx, int sy, int ex, int ey){
    queue<pair<int, int>> q;
    board[sx][sy] = 0;
    q.push({sx, sy});

    
    while (!q.empty())
    {
        auto cur = q.front(); 
        q.pop();
        int cx = cur.first;
        int cy = cur.second;

        if(cx == ex && cy == ey){
            return board[cx][cy];
        }

        for(int i = 0; i < 8; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if(board[nx][ny] != -1) continue;

            board[nx][ny] = board[cx][cy] + 1;
            q.push({nx,ny});
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> l;

        for(int k = 0; k < l; k++){
            fill(board[k], board[k]+l, -1);
        }

        int x, y, ex, ey;
        cin >> x >> y >> ex >> ey;

        cout << bfs(x, y, ex, ey) << "\n";
    }

    return 0;
}