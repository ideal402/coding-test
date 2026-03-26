#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[9][2];
int mx;
int cnt;

void dfs(int k){
    if(k == n){
        mx = max(mx, cnt);
        return;
    }
    if(arr[k][0] <= 0 || cnt == n-1){
        dfs(k+1);
        return;
    }
    for(int i = 0; i < n; i++){
        if(i==k || arr[i][0] <= 0) continue;
        arr[i][0] -= arr[k][1];
        arr[k][0] -= arr[i][1];
        if(arr[i][0] <= 0) cnt++;
        if(arr[k][0] <= 0) cnt++;
        dfs(k+1);
        if(arr[i][0] <= 0) cnt--;
        if(arr[k][0] <= 0) cnt--;
        arr[i][0] += arr[k][1];
        arr[k][0] += arr[i][1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    dfs(0);

    cout << mx;
    

    return 0;
}

