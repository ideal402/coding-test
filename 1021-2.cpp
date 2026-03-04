#include <iostream>
#include <deque>

using namespace std;

int m, n;
deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    int ans = 0;

    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        unsigned long cnt = 0;

        while(dq.front() != temp){
            dq.push_back(dq.front());
            dq.pop_front();
            cnt++;
        }

        ans += min(cnt, dq.size()-cnt);
        dq.pop_front();

    }
    

    return 0;
}