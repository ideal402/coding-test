#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, w, h;
string s;
int visit[1002][1002];
int fire[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> f;
queue<pair<int, int>> q;

void bfs_f(){
    while (!f.empty())
    {
        auto cur = f.front();
        f.pop();

        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];   
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(fire[nx][ny] != 0) continue;

            fire[nx][ny] = fire[cur.X][cur.Y]+1;
            f.push({nx, ny});
        }
    }
}

int bfs(){

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];   
            int ny = cur.Y + dy[i];
            
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                return visit[cur.X][cur.Y];
            };
            if(visit[nx][ny] != 0 ) continue;
            if(fire[nx][ny] != 0 && visit[cur.X][cur.Y] + 1 >= fire[nx][ny]) continue;

            visit[nx][ny] = visit[cur.X][cur.Y]+1;
            q.push({nx, ny});
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> w >> h;
        
        while(!q.empty()) q.pop();
        
        for(int j = 0; j<h; j++){
            cin >> s;
            for(int k = 0; k<w; k++){
                if(s[k] == '#') {
                    visit[j][k] = -1;
                    fire[j][k] = -1;
                }
                else if(s[k] == '*') {
                    f.push({j,k});
                    fire[j][k] = 1;
                }
                else if(s[k] == '@') {
                    q.push({j,k});
                    visit[j][k] = 1;
                }
                else{
                    visit[j][k] = 0;
                    fire[j][k] = 0;
                }
            }
        }

        bfs_f();
        int ans = bfs();

        if(ans != -1){
            cout << ans <<"\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}