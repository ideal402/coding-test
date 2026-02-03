#include <iostream>
#include <algorithm>
#include <queue>

#define INF 0x7f7f7f7f
#define DIST first
#define IDX second

using namespace std;

int v, e;
vector<pair<int, int>> adj[200004];
int d[200004];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    fill(d, d+1+v, INF);

    int start;
    cin >> start;
    d[start] = 0;

    priority_queue<pair<int, int>, 
                vector<pair<int, int>>,
                greater<pair<int,int>>> pq;

    pq.push({0, start});

    int f, t, w;
    for(int i = 0; i < e; i++){
        cin >> f >> t >> w;
        adj[f].push_back({w,t});
    }

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(d[cur.IDX] != cur.DIST) continue;
        
        for(auto nxt: adj[cur.IDX]){
            if(d[cur.IDX] + nxt.DIST < d[nxt.IDX]){
                d[nxt.IDX] = d[cur.IDX] + nxt.DIST;
                pq.push({d[nxt.IDX], nxt.IDX});
            }
        }
    }

    for(int i = 1; i < v+1; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";   
    }
    
    return 0;
}