#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool check[10005];
priority_queue< tuple<int,int,int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;

vector<pair<int, int>> adj[10005];

int cnt;

int v, e;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    
    int a, b, cost;

    for(int i = 1; i < e+1; i++){
        cin >> a >> b >> cost;
        
        adj[a].push_back({b, cost});
        adj[b].push_back({a, cost});
    }


    for(auto x: adj[1]){
        tie(b, cost) = x;    
        pq.push(make_tuple(cost, 1, b));
    }
    check[1] = true;

    int ans = 0;

    while (cnt != v-1)
    {
        tie(cost, a, b) = pq.top();
        pq.pop();

        if(check[b]) continue;
        check[b] = true;
        ans += cost;
        cnt++;

        for(auto x: adj[b]){
            tie(a, cost) = x;    
            pq.push(make_tuple(cost, b, a));
        }
    }
    

    cout << ans;
    return 0;
}