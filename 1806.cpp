#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> arr[i];   
    }

    int st = 0;
    int en = 0;
    int sum = 0;
    int ans = n+1;

    for(en = 0; en<n; en++){
        sum += arr[en];

        while(sum >= m){
            ans = min(ans, en-st+1);
            sum -= arr[st++];
        }
    }

    if(ans > n){
        cout << 0;
    }
    else{
        cout << ans;
    }   

    return 0;
}