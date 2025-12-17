#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[1002];
    int two[1100000];

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> arr[i];   
    }
    sort(arr,arr+n);

    int idx = 0;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            two[idx++] = arr[i] + arr[j];
        }   
    }

    sort(two, two+idx);
    int len = unique(two, two+idx) - two;
    
    for(int i = n-1; i>0; i--){
        for(int j = 0; j < n; j++){
            if(binary_search(two, two+len, arr[i]-arr[j])){
                cout << arr[i];
                return 0;
            }
        }
    }

    return 1;
}