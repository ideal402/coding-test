#include <iostream>
#include <algorithm>

#define INF 0x7f7f7f7f

using namespace std;

bool visit[6];
int d[6];
vector<pair<int, int>> adj[6];

void dijkstra(int start){
    int cnt = 1;

    fill(d, d+6, INF);

    d[start] = 0;
    
    while(true){
        int idx = -1;

        for(int i = 0; i < 6; i++){
            if(visit[i]) continue;
            if(idx == -1) idx = i;
            else if(d[i] < d[idx]) idx = i;
        }
        if(idx == -1 || d[idx] == INF) break;

        visit[idx] = 1;

        for(auto x: adj[idx]){

            d[x.second] = min(d[x.second], d[idx] + x.first);
        }
    }
}

int main(){
    
    return 0;
}