#include <iostream>
#include <algorithm>

using namespace std;

int a;
int arr[10];

int main(){
    cin >> a;

    while(a>0){
        arr[a%10]++;
        a /= 10;
    }

    int ans = 0;

    arr[6] += arr[9];
    arr[6] = arr[6]/2 + arr[6]%2;
    arr[9] = arr[6];

    for(int i=0; i<10; i++){
        ans = max(ans, arr[i]);
    }

    cout << ans;
    return 0;
}