#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int dist[MAX + 5]; // 방문 여부 및 최단 시간 기록

int bfs(int n, int k) {
    deque<int> dq;
    
    // 시작 위치 초기화
    dq.push_back(n);
    dist[n] = 0; 

    while (!dq.empty()) {
        int current = dq.front();
        dq.pop_front();

        // 목표 위치 도달 시 즉시 종료 (0-1 BFS는 첫 Pop이 최단 경로임을 보장)
        if (current == k) {
            return dist[current];
        }

        // 1. 순간이동 (X * 2): 가중치 0 -> 덱의 앞(front)에 삽입
        int next_teleport = current * 2;
        if (next_teleport <= MAX && dist[next_teleport] == -1) {
            dist[next_teleport] = dist[current];
            dq.push_front(next_teleport);
        }

        // 2. 뒤로 걷기 (X - 1): 가중치 1 -> 덱의 뒤(back)에 삽입
        int next_walk_back = current - 1;
        if (next_walk_back >= 0 && dist[next_walk_back] == -1) {
            dist[next_walk_back] = dist[current] + 1;
            dq.push_back(next_walk_back);
        }

        // 3. 앞으로 걷기 (X + 1): 가중치 1 -> 덱의 뒤(back)에 삽입
        int next_walk_forward = current + 1;
        if (next_walk_forward <= MAX && dist[next_walk_forward] == -1) {
            dist[next_walk_forward] = dist[current] + 1;
            dq.push_back(next_walk_forward);
        }
    }
    return -1;
}

int main() {
    // 입출력 속도 향상 (Fast I/O)
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 배열을 -1(미방문 상태)로 초기화
    // 0초가 걸리는 위치가 존재하므로, 0 대신 -1로 미방문 상태를 명확히 구분해야 함
    fill(dist, dist + MAX + 5, -1);

    cout << bfs(n, k) << '\n';

    return 0;
}