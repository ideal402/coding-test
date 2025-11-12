#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n;
char board_1[102][102];
char board_2[102][102];
int v_1[102][102];
int v_2[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int x, int y, int visit[][102], char board[][102]){
    queue<pair<pair<int,int>, char>> q;

    visit[x][y] = 1;
    q.push({{x,y}, board[x][y]});

    while(!q.empty()){
        auto temp = q.front();
        auto cur = temp.X;
        char pre = temp.Y;

        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visit[nx][ny] == 0 && board[nx][ny] == pre){
                visit[nx][ny] = 1;
                q.push({{nx, ny}, board[nx][ny]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i =0; i<n; i++){
        string temp;
        cin >> temp;

        for(int j=0; j<n; j++){
            if(temp[j]=='G'){
                board_2[i][j] = 'R';
            }
            else{
                board_2[i][j] = temp[j];
            }
                board_1[i][j] = temp[j];
        }
    }

    int ans_1 = 0;
    int ans_2 = 0;

    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v_1[i][j] == 0){
                bfs(i,j,v_1,board_1);
                ans_1++;
            }
            if(v_2[i][j] == 0){
                bfs(i,j,v_2,board_2);
                ans_2++;
            }
        }
    }

    cout << ans_1 << " " << ans_2;
    return 0;
}