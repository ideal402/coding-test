#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map_1[102][102];
int map_2[102][102];

int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int s_x, int s_y, int (*map)[102]){
    queue<pair<int, int>> q;
    int val = map[s_x][s_y];
    map[s_x][s_y] = -1;
    q.push({s_x, s_y});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cx = cur.first;
        int cy = cur.second;

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(map[nx][ny] != val) continue;

            q.push({nx, ny});
            map[nx][ny] = -1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        
        for(int j = 0; j < n; j++){
            if(temp[j] == 'R'){
                map_1[i][j] = 0;
                map_2[i][j] = 0;
            }
            else if(temp[j] == 'G'){
                map_1[i][j] = 1;
                map_2[i][j] = 0;
            }
            else{
                map_1[i][j] = 2;
                map_2[i][j] = 2;
            }
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map_1[i][j] != -1){
                bfs(i,j,map_1);
                cnt1++;     
            }
            if(map_2[i][j] != -1){
                bfs(i,j,map_2);
                cnt2++;
            }
        }   
    }

    cout << cnt1 << " " << cnt2;

    return 0;
}