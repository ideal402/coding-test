#include <iostream>
#include <vector>

using namespace std;

int n, m;
    
int dfs(int x, int y, vector<vector<int>>& maps, vector<vector<int>>& v){
    
    if (x == m-1 && y == n-1){
        cout << "asdf";
        return 1;
    }
    if (v[y][x] != -1){
        return v[y][x];
    }

    v[y][x] = 0;

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if (0<= nx && nx < m && 0 <= ny && ny < n){
            if(maps[y][x] > maps[ny][nx]){
                v[ny][nx] += dfs(nx, ny, maps, v);
            }
        }
    }

    return v[y][x];

}

int main(){
    cin >> n >> m;
    vector<vector<int>> maps(n, vector<int> (m));
    vector<vector<int>> v(n, vector<int> (m,-1));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
        }
    }


    cout << dfs(0,0,maps,v);
    
    for(auto x: v){
        for(auto y: x){
            cout << y << " ";
        }
        cout <<"\n";
    }

    return 0;
}
