#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char board[5][5]; 
int visited[5][5]; // 조합(Combination) 선택 여부 표시용 (1: 선택, 0: 미선택)
int ans = 0;

// 연결 요소(Connected Component) 검사를 위한 너비 우선 탐색 (BFS)
bool bfs(int start_x, int start_y){
    queue<pair<int, int>> q;
    int bfs_visited[5][5] = {0, }; // 상태 오염 방지를 위한 지역 배열 선언
    
    q.push({start_x, start_y});
    bfs_visited[start_x][start_y] = 1; // 시작 정점 방문 처리
    int connected_cnt = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 격자 범위 이탈 검사 (Out of Bounds)
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            // 미선택된 정점이거나, 이미 BFS로 방문한 정점이면 패스
            if(visited[nx][ny] == 0 || bfs_visited[nx][ny] == 1) continue;

            bfs_visited[nx][ny] = 1;
            q.push({nx, ny});
            connected_cnt++;
        }
    }
    
    // 7개의 정점이 모두 연결되어 있는지 반환
    return connected_cnt == 7;
}

// 조합 구성을 위한 깊이 우선 탐색 (DFS) 및 백트래킹 (Backtracking)
void dfs(int idx, int cnt, int y_cnt) {
    // 1. 가지치기 (Pruning): 임도연파가 4명 이상인 경우 탐색 조기 종료
    if (y_cnt >= 4) return;

    // 2. 기저 조건 (Base Condition): 7명을 모두 선택한 경우
    if (cnt == 7) {
        int start_x = -1, start_y = -1;
        // 탐색의 시작 정점 찾기
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (visited[i][j] == 1) {
                    start_x = i; 
                    start_y = j;
                    break;
                }
            }
            if (start_x != -1) break; // 찾았으면 이중 루프 탈출
        }
        
        // 연결 요소 검증
        if (bfs(start_x, start_y)) {
            ans++;
        }
        return;
    }

    // 3. 기저 조건 (Base Condition): 25개 좌표를 모두 탐색하여 인덱스 범위를 초과한 경우
    if (idx == 25) return;

    int r = idx / 5;
    int c = idx % 5;

    // --- 상태 전이 (State Transition) ---

    // Option A: 현재 노드(정점)를 포함하는 경우
    visited[r][c] = 1;
    int is_y = (board[r][c] == 'Y') ? 1 : 0;
    dfs(idx + 1, cnt + 1, y_cnt + is_y);
    
    // Option B: 현재 노드(정점)를 포함하지 않는 경우 (백트래킹)
    visited[r][c] = 0;
    dfs(idx + 1, cnt, y_cnt);
}

int main(){
    // 입출력 성능 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < 5; j++){
            board[i][j] = temp[j];
        }
    }
    
    // 탐색 시작 (초기 상태: 인덱스 0, 선택 인원 0, Y 인원 0)
    dfs(0, 0, 0);

    cout << ans;

    return 0;
}