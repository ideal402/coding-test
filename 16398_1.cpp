#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> adj[1004];
bool chk[1004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int c;
            cin >> c;
            if(i >= j) continue;
            adj[i].push_back({c, j});
            adj[j].push_back({c, i});
        }   
    }
    int cnt = 0;
    long long ans = 0;

    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;

    chk[1] = true;
    for(auto nxt: adj[1]) pq.push(nxt);
    
    while(cnt < n-1){
        auto cur = pq.top();
        pq.pop();
        if(chk[cur.second]) continue;
        ans += cur.first;
        cnt++;
        for(auto nxt: adj[cur.second]){
            if(!chk[nxt.second]) pq.push(nxt);
        }
    }

    cout << ans;
    
    return 0;
}