#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int ans[10];
bool issued[10];
int arr[10];

void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        if(issued[i]) continue;
        ans[k] = arr[i];
        issued[i] = true;
        func(k+1);
        issued[i] = false;
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr+1, arr+n+1);

    func(0);

    return 0;
}