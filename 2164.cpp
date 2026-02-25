#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


queue<int> q;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        q.push(i+1);
    }

    while (q.size() != 1)
    {
        q.pop();
        int x = q.front();
        q.push(x);
        q.pop();
    }
    
    cout << q.front();

    return 0;
}