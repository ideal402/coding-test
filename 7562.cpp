#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, l;
int visit[302][302];
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(int s_x, int s_y, int e_x, int e_y){
    queue<pair<int, int>> q;

    visit[s_x][s_y] = 0;
    q.push({s_x, s_y});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        if(cur.first == e_x && cur.second == e_y){
            return visit[cur.first][cur.second];
        }

        for(int i = 0; i<8; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if(visit[nx][ny] != -1) continue;

            visit[nx][ny] = visit[cur.first][cur.second] + 1;
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
        cin >> l;
        int s_x, s_y, e_x, e_y;

        cin >> s_x >> s_y >> e_x >> e_y;

        for(int i = 0; i<l; i++){
            fill(visit[i], visit[i]+l, -1);
        }
        cout << bfs(s_x, s_y, e_x, e_y) << "\n"; 

    }


    return 0;
}