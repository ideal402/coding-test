#include <iostream>
#include <algorithm>

using namespace std;

bool check(int n){
    if(n == 1) return 0;

    for(int i = 2; i*i<=n; i++){   
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int ans = 0;

    cin >> n;

    for(int i = 0; i<n; i++){
        int temp;

        cin >> temp;

        if(check(temp)){
            ans++;
        }
    }

    cout << ans;
    return 0;
}