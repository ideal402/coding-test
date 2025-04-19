#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int m, n;
    cin >> n >> m;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int left = 0, right = 0;
    int ans = 2000000000;

    while (right < n){

        if (a[right]-a[left] >= m){
            ans = min(ans, a[right]-a[left]);
            left++;
        } 
        else{
            right++;
        }

        if(left == right) right++;
    }

    cout << ans ;

    return 0;
}

