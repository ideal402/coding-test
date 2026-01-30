#include <iostream>
#include <algorithm>

using namespace std;

int v, e;
int p[10004];
tuple<int, int, int> edge[100004];

int my_find(int u){    
    if(p[u] == u) return u;
    return p[u] = my_find(p[u]);
}

void my_union(int u, int v){
    int root_u = my_find(u);
    int rooy_v = my_find(v);

    if(root_u != rooy_v){
        p[root_u] = rooy_v;
    }
}

int isUnion(int u, int v){
    return (my_find(u) == my_find(v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    for(int i = 0; i < v; i++){
        p[i] = i;
    }

    int a, b, c;

    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        
        edge[i] = make_tuple(c, a, b);
    }
    
    sort(edge, edge+e);

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++){
        tie(c, a, b) = edge[i];

        if(isUnion(a, b)) continue;
        my_union(a, b);
        cnt++;
        ans += c;

        if(cnt == v-1) break;
    }

    cout << ans;

    return 0;
}