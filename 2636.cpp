#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m;

int bfs(int x, int y, vector<vector<int>>& c){
    queue<pair<int, int>>  q;

    q.push({x, y});
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> v(n, vector<int>(m, 0));
    set<pair<int, int>> melt;

    while (!q.empty())
    {
        int cx, cy;
        cx = q.front().first;
        cy = q.front().second;
        q.pop();    

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny <n && v[ny][nx] == 0){
                if(c[ny][nx]==1){
                    melt.insert({nx, ny});
                }
                if(c[ny][nx]==0){
                    v[ny][nx] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for(auto x: melt){
        c[x.second][x.first] = 0;
    }
    
    return melt.size();
}

int main(){
    cin >> n >> m;
    vector<vector<int>> cheese(n, vector<int>(m));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> cheese[i][j];
        }
    }

    int time = 0, last = 0;

    while (true){
        int melted = bfs(0, 0, cheese);

        if (melted == 0) break;
        last = melted;
        time++;
    }

    cout << time << "\n" << last << endl;

    return 0;
}
