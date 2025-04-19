#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    for(int i=0; i<m; i++){
        cin>>a[i];
    }

    int ans = 0;

    for(int i=1; i<m-1; i++){
        int left_max = 0, right_max = 0;

        for(int j=0; j<i; j++){
            right_max = max(right_max, a[j]);
        }
        
        for(int j=i+1; j<m; j++){
            left_max = max(left_max, a[j]);
        }
        int diff = min(left_max, right_max) - a[i];
        if (diff>0){
            ans += diff;  
        }
    }

    cout << ans;
}