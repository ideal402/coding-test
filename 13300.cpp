#include <iostream>

using namespace std;

int n, k;
int arr[7][2];

int main(){
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int s, y;
        cin >> s >> y;
        arr[y][s]++;
    }

    int ans = 0;

    for(int i=1; i<7; i++){
        ans += arr[i][0]/k; 
        if(arr[i][0]%k) ans++; 
        ans += arr[i][1]/k; 
        if(arr[i][1]%k) ans++;
    }

    cout << ans;

    return 0;
}