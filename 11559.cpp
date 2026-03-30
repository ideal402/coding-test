#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


bool isPuyo;
bool vis[12][6];
string board[12];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int ans;

void resetvis(){
    for(int i = 0; i < 12; i++){
        fill(vis[i], vis[i]+6, false);
    }
}

void puyo(int x, int y){
    bool doErase = false;
    vis[x][y] = true;
    char color = board[x][y];
    queue<pair<int, int>> q;
    vector<pair<int,int>> temp;

    q.push({x,y});
    temp.push_back({x,y});

    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] == '.' || board[nx][ny] != color) continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
            temp.push_back({nx, ny});
        }
    }

    if(temp.size() >= 4){
        isPuyo = true;
        for(auto cur: temp){
            board[cur.first][cur.second] = '.';
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 12; i++){
        cin >> board[i];
    }

    do{
        isPuyo = false;
        for(int i = 0; i < 6; i++){
            for(int j = 10; j >= 0; j--){
                int temp = j;

                while(temp < 11 && board[temp+1][i] == '.'){
                    swap(board[temp][i], board[temp+1][i]);
                    temp++;
                }
            }
        }
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(!vis[i][j] && board[i][j] != '.'){
                    puyo(i, j);
                }
            }
        }
        if(isPuyo) ++ans;
        resetvis();
    }while(isPuyo);

    cout << ans;

    return 0;
}