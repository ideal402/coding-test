#include <iostream>

using namespace std;

int n, m, x, y;
int a[100005];
int dp[100005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
    }

    for(int i=0; i<m; i++){
        cin >> x >> y;
        cout << dp[y] - dp[x-1] << "\n";
    }


    return 0;
}