#include <iostream>
#include <algorithm>

using namespace std;

int n, temp;
int arr[1000004];
int arr2[1000004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        arr[i] = temp;
        arr2[i] = temp;
    }

    sort(arr2, arr2+n);

    int last = unique(arr2, arr2+n) - arr2;

    for(int i = 0; i<n; i++){
        int lower = lower_bound(arr2, arr2+last, arr[i]) - arr2;
        cout << lower << " ";    
    }

    return 0;
}