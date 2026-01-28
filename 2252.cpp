#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int n,m;
vector<int> adj[32001];
int in_deg[320001];

queue<int> q;
vector<int> result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;

        adj[a].push_back(b);
        in_deg[b]++;
    }

    for(int i = 1; i < n+1; i++){
        if(in_deg[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        result.push_back(cur);

        for(auto next: adj[cur]){
            if(--in_deg[next] == 0){
                q.push(next);
            }
        }
    }
    
    for(auto x: result){
        cout << x << " ";
    }
    
    return 0;
}