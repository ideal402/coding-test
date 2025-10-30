#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[100001];


int main(){
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];        
    }

    sort(arr, arr+n);

    long long mx_val = -(1ll << 62) - 1;
    int mx_cnt = 0;
    int cnt = 0;

    for(int i=0; i<n; i++){
        if(i == 0 || arr[i-1] == arr[i]) cnt++;
        else{
            if(mx_cnt < cnt){
                mx_cnt = cnt;
                mx_val = arr[i-1];
            }
            cnt = 1;
        }  
    }

    if(mx_cnt < cnt) mx_val = arr[n-1];
    cout << mx_val; 
}

