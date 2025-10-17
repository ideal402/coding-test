#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, m;
int board[1000][1000];
int dist[1000][1000];
int dist2[1000][1000];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    cin >> n >> m;
    int s_x, s_y;
    pair<int, int> cur;
    string temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=0; j<m; j++){
            board[i][j] = temp[j];
            dist[i][j] = -1;
            dist2[i][j] = -1;
            if(board[i][j] == 'J'){
                s_x = i;
                s_y = j;            
            }
            if(board[i][j] == 'F'){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    
    while(!q.empty()){
        cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }  

    dist2[s_x][s_y] = 0;
    q.push({s_x, s_y});

    while(!q.empty()){
        cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << dist2[cur.X][cur.Y]+1;
                return 0;
            };

            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1 && dist[nx][ny] <= dist2[cur.X][cur.Y]+1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }  

    cout << "IMPOSSIBLE";
}  