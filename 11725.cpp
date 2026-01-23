#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> adj[100004];
int p[100004];

void bfs(int root){
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next: adj[cur]){
            if(p[cur] == next) continue;
            p[next] = cur;
            
            q.push(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    int u, v;

    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    for(int i = 2; i < n+1; i++){
        cout << p[i] << "\n";
    }



    return 0;
}