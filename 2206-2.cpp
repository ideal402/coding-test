//26.03.07
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int board[1002][1002];
int visit[1002][1002][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(){
    queue<tuple<int, int, int>> q;
    visit[0][0][0] = 1;
    visit[0][0][1] = 1;
    q.push({0,0,0});

    while(!q.empty()){
        auto [cx, cy, b] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(b == 0){
                if(board[nx][ny] == 1){
                    if(visit[nx][ny][1] != 0 && visit[nx][ny][1] <= visit[cx][cy][0] + 1) continue;

                    visit[nx][ny][1] = visit[cx][cy][0] + 1;
                    q.push({nx, ny, 1});
                }
                else{
                    if(visit[nx][ny][0] != 0 && visit[nx][ny][0] <= visit[cx][cy][0] + 1) continue;
                    
                    visit[nx][ny][0] = visit[cx][cy][0] + 1;
                    q.push({nx, ny, 0});
                }
            }
            else{
                if(board[nx][ny] == 1) continue;
                if(visit[nx][ny][1] != 0 && visit[nx][ny][1] <= visit[cx][cy][1] + 1) continue;
                
                visit[nx][ny][1] = visit[cx][cy][1] + 1;
                q.push({nx, ny, 1});
        
            }            
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string temp;

        cin >> temp;
        
        for(int j = 0; j < m; j++){
            board[i][j] = temp[j]-'0';
        }
    }

    bfs();


    if(visit[n-1][m-1][0] != 0 && visit[n-1][m-1][1] != 0){
        cout << min(visit[n-1][m-1][0], visit[n-1][m-1][1]);
    }
    else if(visit[n-1][m-1][0] == 0 && visit[n-1][m-1][1] == 0){
        cout << -1;
    }
    else{
        cout << max(visit[n-1][m-1][0], visit[n-1][m-1][1]);
    }


    return 0;
}