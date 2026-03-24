#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int k[10];

void func(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << k[i] << " "; 
        }
        cout << "\n";
        return;
    }
    int st = 1;
    if(cnt != 0) st = k[cnt-1] + 1;
    for(int i = st; i <= n; i++){
        k[cnt] = i;
        func(cnt+1);
    }
    return;
}

int arr[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        arr[i]= 1;
    }
    for(int i = m; i < n; i++){
        arr[i] = 0;
    }

    do{
        for(int i = 0; i < n; i++){
            if(arr[i]) cout << i+1 << " ";
        }
        cout << "\n";
    }while(prev_permutation(arr, arr+n));

    return 0;
}