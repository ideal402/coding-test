#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    int low = 0, high = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        low = max(low, arr[i]);  
        high += arr[i];
    }
    
    int result = high;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = 1, cash = mid;
        
        for (int i = 0; i < n; i++) {
            if (cash < arr[i]) {
                cnt++;
                cash = mid;
            }
            cash -= arr[i];
        }
        
        if (cnt > m) {
            low = mid + 1;
        } else {
            result = mid;
            high = mid - 1;
        }
    }
    
    cout << result << "\n";
    return 0;
}