#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int n, m;
int board[500][500];
bool visit[500][500];


int bfs(int s_x, int s_y){
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    int cnt = 1;

    queue<pair<int, int>> q;

    q.push({s_x, s_y});
    visit[s_x][s_y] = true;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            if(visit[nx][ny]||board[nx][ny] == 0) continue; 

            visit[nx][ny] = true;
            cnt++;
            q.push({nx, ny});
        }
    }

    return cnt;
}

int main(){
    
    cin >> n >> m;


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
            visit[i][j] = false;
        }
    }

    int count = 0;
    int temp = 0;
    int max = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visit[i][j] && board[i][j] == 1){
                
                count++;

                temp = bfs(i, j);

                if(temp > max){
                    max = temp;
                }
            }
        }
    }

    cout << count << "\n" << max;
    return 0;
}