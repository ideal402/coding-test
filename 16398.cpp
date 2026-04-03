#include <iostream>
#include <algorithm>

using namespace std;

int n;
int s, e, c;

int p[1004];
vector<tuple<int, int, int>> edge;

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v){
    u = find(u); v = find(v);

    if(u==v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;

    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(p, p+n, -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            if(i==j) continue;
            edge.push_back(make_tuple(c,i,j));
        }
    }

    sort(edge.begin(), edge.end());

    int u, v;
    int cnt = 0;

    long long ans = 0;

    for(auto e: edge){
        tie(c,u,v) = e;
        if(!merge(u, v)) continue;
        ans += c;
        cnt++;
        if(cnt == n-1) break;
    }

    cout << ans;

    return 0;
}