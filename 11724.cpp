#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int u, v;


    vector<int> arr[n];
    
    for(int i = 0; i < m; i++){
        cin >> u >> v;

        arr[u-1].push_back(v-1);
        arr[v-1].push_back(u-1);
    }

    int visit[n];

    fill(visit, visit+n, -1);

    int ans = 0;

    for(int i = 0; i < n; i++){
        
        if(visit[i] == 1) continue;
        
        ans++;
        queue<int> q;
        q.push(i);
        visit[i] = 1;

        while(!q.empty()){

            int idx = q.front(); q.pop();

            for(auto x: arr[idx]){
                if(visit[x] == 1) continue;
                q.push(x);
                visit[x] = 1;
            }
        }
        
    }

    cout << ans;

    return 0;
}