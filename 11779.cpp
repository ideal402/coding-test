#include <iostream>
#include <algorithm>
#include <queue>

#define INF 100000003
#define DIST first
#define IDX second

using namespace std;

int n, m;
vector<pair<int, int>> adj[200004];
int d[200004];
int p[200004];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(d, d+1+n, INF);

    int f, t, w;
    for(int i = 0; i < m; i++){
        cin >> f >> t >> w;
        adj[f].push_back({w,t});
    }

    int start, end;
    cin >> start >> end;
    priority_queue<pair<int, int>, 
                vector<pair<int, int>>,
                greater<pair<int,int>>> pq;

    d[start] = 0;
    pq.push({0, start});


    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(d[cur.IDX] != cur.DIST) continue;
        
        for(auto nxt: adj[cur.IDX]){
            if(d[cur.IDX] + nxt.DIST < d[nxt.IDX]){
                d[nxt.IDX] = d[cur.IDX] + nxt.DIST;
                p[nxt.IDX] = cur.IDX;
                pq.push({d[nxt.IDX], nxt.IDX});
            }
        }
    }

    vector<int> ans;

    int idx = end;

    while(idx != start){
        ans.push_back(idx);
        idx = p[idx];
    }
    ans.push_back(start);

    reverse(ans.begin(), ans.end());
    
    cout << d[end] << "\n";
    cout << ans.size() << "\n";
    for(auto x: ans){
        cout << x << " ";
    }


    
    return 0;
}