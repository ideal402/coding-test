#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[32004];
vector<int> adj[32004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int a, b;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        arr[b]++;
        adj[a].push_back(b);
    }

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(arr[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur <<" ";

        for(auto nxt: adj[cur]){
            if(--arr[nxt] == 0) q.push(nxt);
        }
    }

    return 0;
}