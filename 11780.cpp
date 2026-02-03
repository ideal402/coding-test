#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int n, m;
int d[102][102];
int nxt[102][102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fill(d[i], d[i]+n+1, INF);   
    }

    int from, to, cost;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> cost;

        if(d[from][to] >= cost){
            d[from][to] = cost;
            nxt[from][to] = to;
        }
    }
    
    for(int i = 1; i <= n; i++){
        d[i][i] = 0;   
    }
    int cnt = n;

    for(int a = 1; a <= n; a++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (d[i][j] > d[i][a]+d[a][j]){
                    d[i][j] = d[i][a]+d[a][j];
                    nxt[i][j] = nxt[i][a];
                }
            }   
        }   
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << " ";
        }   
        cout << "\n";
    }    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(d[i][j] == 0 || d[i][j] == INF){
                cout << 0 << "\n";
                continue;
            }
            vector<int> ans = {i};
            int next=nxt[i][j];
            ans.push_back(next);

            while(next != j){
                next = nxt[next][j];
                ans.push_back(next);
            }
            cout << ans.size() << " ";
            for(auto x: ans){
                cout << x << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}