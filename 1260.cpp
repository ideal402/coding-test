#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, start;
int visit[1004];
vector<int> arr[1004];

// void dfs(int idx){
//     fill(visit, visit+n, 0);

//     stack<int> s;
//     s.push(idx);
//     visit[idx] = 1;
//     cout << idx+1 << " ";

//     while(!s.empty()){
//         int c_idx = s.top(); s.pop();
//         for(int x: arr[c_idx]){
//             if(visit[x] == 1) continue;
//             s.push(x);
//             visit[x] = 1;
//             cout << x+1 << " ";
//         }
//     }
// }

void dfs(int idx){

    visit[idx] = 1;
    cout << idx+1 << " ";

    for(int x: arr[idx]){
        if(visit[x] == 1) continue;
        dfs(x);
    }
}

void bfs(int idx){
    fill(visit, visit+n, 0);

    queue<int> q;
    q.push(idx);
    visit[idx] = 1;
    cout << idx+1 << " ";
    
    while(!q.empty()){
        int c_idx = q.front(); q.pop();

        for(int x: arr[c_idx]){
            if(visit[x] == 1) continue;
            q.push(x);
            visit[x] = 1;
            cout << x+1 << " ";

        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;
    
    int u, v;

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        arr[u-1].push_back(v-1);
        arr[v-1].push_back(u-1);    
    }

    for(int i = 0; i < n; i++){
        sort(arr[i].begin(), arr[i].end());   
    }

    dfs(start-1);

    cout << "\n";
    
    bfs(start-1);
    

    return 0;
}