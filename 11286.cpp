#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        // 절댓값이 작은 것을 우선
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

int main() {
    int n, temp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (temp == 0) {
            if (!pq.empty()) {
                cout << pq.top().second << "\n";
                pq.pop();
            } else {
                cout << 0 << "\n";
            }
        } else {
            pq.push({abs(temp), temp});
        }
    }

    return 0;
}
