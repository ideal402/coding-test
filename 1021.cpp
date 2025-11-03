#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;
deque<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        q.push_back(i);
    }

    int ans = 0;

    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        unsigned long cnt = 0;

        while(temp != q.front()){
            q.push_back(q.front());
            q.pop_front();
            cnt++;
        }
        ans += min(cnt, q.size()-cnt);
        q.pop_front();
    }

    cout << ans;
    
    return 0;
}