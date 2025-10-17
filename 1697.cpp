#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, k;
int dist[100001];
queue<int> q;

int main(){
    cin >> n >> k;

    if (n == k) {
        cout << 0;
        return 0;
    }
    
    fill(dist, dist+100001, -1);
    dist[n]=0;
    q.push(n);

    while(dist[k] == -1){
        int cur = q.front(); q.pop();
        
        int nx1 = cur+1;
        int nx2 = cur-1;
        int nx3 = cur*2;
        
        if(nx1 > -1 && nx1 < 100001 && dist[nx1] == -1){
            dist[nx1] = dist[cur] + 1;
            q.push(nx1);
        }
        if(nx2 > -1 && nx2 < 100001 && dist[nx2] == -1){
            dist[nx2] = dist[cur] + 1;
            q.push(nx2);
        }
        if(nx3 > -1 && nx3 < 100001 && dist[nx3] == -1){
            dist[nx3] = dist[cur] + 1;
            q.push(nx3);
        }
    }

    cout << dist[k];
    return 0;
}