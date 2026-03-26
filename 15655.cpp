#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[10];
int ans[10];

void func(int k, int st){
    if(k == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] <<" ";
        }
        cout << "\n";
        return;
    }
    for(int i = st; i <= n; i++){
        ans[k] = arr[i];
        func(k+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+n);
    func(0,1);

    return 0;
}