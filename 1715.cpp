#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, temp;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> temp;
        pq.push(temp);
    }

    long long ans = 0;

    while(pq.size() >= 2){
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        ans += a+b;
        pq.push(a+b);
    }

    cout << ans;

    return 0;
}