#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int map[52][52];
int t, m, n, k;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int start_x, int start_y){
    queue<pair<int, int>> q;
    map[start_x][start_y] = 2;
    q.push({start_x, start_y});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int n_x = cur.X + dx[i];
            int n_y = cur.Y + dy[i];

            if(n_x < 0 || n_x >= m || n_y < 0 || n_y >= n) continue;
            if(map[n_x][n_y] == 0 || map[n_x][n_y] == 2) continue;
            
            q.push({n_x, n_y});
            map[n_x][n_y] = 2;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for(int i = 0; i < t; i++){
        int cnt = 0;
        cin >> m >> n >> k;
        
        for(int k = 0; k<m; k++){
            fill(map[k], map[k]+n, 0);
        }

        for(int i = 0; i < k; i++){
            int t_x, t_y;
            cin >> t_x >> t_y;

            map[t_x][t_y] = 1;
        }


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == 1){
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n"; 
    }


    return 0;
}