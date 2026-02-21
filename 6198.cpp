#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> arr;
int n;

// 10 -> 0
// 10, 3 -> 0 + 1
// 10, 7 -> 0 + 1 + 1
// 10, 7, 4 -> 0 + 1 + 1 + 2
// 12 -> 0 + 1 + 1 + 1 + 0
// 12, 2 -> 0 + 1 + 1 + 2 + 0 + 1 = 5

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int temp;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        cin >> temp;
        
        if(arr.empty()) {
            arr.push(temp);
            continue;
        }

        while(!arr.empty() && arr.top() <= temp){
            arr.pop();
        }

        ans += arr.size();

        arr.push(temp);
        
    }

    cout << ans;

    return 0;
}