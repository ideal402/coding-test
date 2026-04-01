#include <iostream>
#include <algorithm>

using namespace std;

//d[i]는 i를 마지막으로 포함하는 배열의 합중 최대값
//d[i] = max(d[i-1] + c[i], c[i]);
//d[0] = 0;

int n;
int d[100004];
int c[100004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> c[i];    
    }

    d[0] = 0;

    for(int i = 1; i <= n; i++){
        d[i] = max(d[i-1] + c[i], c[i]);
    }

    int ans = -1000 * 10000;

    for(int i = 1; i <= n; i++){
        ans = max(ans, d[i]);
    }
    
    cout << ans;

    return 0;
}