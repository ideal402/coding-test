#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 1. 특정 친구부터 타고 들어간다
// 2. 방문했던 곳에 다시 방문한다.
// 3-1. 이미 그룹이 있는 경우 -> 지금까지 경로의 모든 학생을 그룹없음 처리
// 3-2. 그룹이 존재하지 않는 경우 -> 한번더 돌면서 그룹처리 총 O(2N)

int t, n, cnt;
int map[100004];
int visit[100004];

void bfs(int start){
    queue<int> q;
    vector<int> v;

    visit[start] = cnt;
    q.push(start);
    v.push_back(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int nxt = map[cur];

        if(visit[nxt] == 0){
            visit[nxt] = cnt;
            q.push(nxt);
        }
        else if(visit[nxt] == cnt){ 
            int temp = start;
            while(temp != nxt){
                visit[temp] = -1;
                temp = map[temp];
            }
        }
        else{
            int temp = start;
            while(visit[temp] == cnt){
                visit[temp] = -1;
                temp = map[temp];
            }
        }
    }
    cnt++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        cnt = 1;
        
        for(int i = 1; i < n+1; i++){
            cin >> map[i];
            visit[i] = 0;
        }

        for(int i = 1; i < n+1; i++){
            if(visit[i] == 0){
                bfs(i);
            }

        }

        int ans = 0;

        for(int i = 1; i < n+1; i++){
            if(visit[i] == -1) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}