#include <iostream>
#include <algorithm>

using namespace std;

int n;
int s[302];
int dp[302];

int main(){
    cin >> n;
    int ans = 0;
    for(int i=1; i<n+1; i++){
        cin >> s[i];
        ans += s[i];
    }
    
    if(n<=2) {
        cout << ans;
        return 0;
    }

    dp[1] = s[1];
    dp[2] = s[2];
    dp[3] = s[3];
    
    for(int i=4; i<=n; i++){
        dp[i] = min(dp[i-3], dp[i-2])+s[i];
    }

    cout << ans - min(dp[n-2], dp[n-3]);
}