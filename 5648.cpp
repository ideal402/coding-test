#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[1000005];

long long re(long long k){
    long long result = 0;

    while(k >= 10){
        int temp = k%10;
        result = result*10 + temp;
        k /= 10;
    }
    result = result*10 + k;
    
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long temp;

    for(int i = 0; i < n; i++){
        cin >> temp;
        arr[i] = re(temp);
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}