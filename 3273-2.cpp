#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    cin >> x;

    sort(arr, arr+n);

    int s = 0;
    int e = n-1;
    int ans = 0;

    while(s<e){
        int sum = arr[s]+arr[e];
        if(sum > x) e--;
        else if(sum < x) s++;
        else {
            ans++;
            s++;
        }
    }
    
    cout << ans;

    return 0;
}