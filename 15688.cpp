#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int temp;
    int arr[2000002] {0};
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        arr[temp+1000000]++;
    }

    for(int i=0; i<=2000000; i++){
        while(arr[i]--){
            cout << i-1000000 << "\n"; 
        }
    }
}