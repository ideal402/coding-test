#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);
    if (n>=3) dp[3] = 1;
    if (n>=5) dp[5] = 1;

    for (int i = 6; i<=n; i++){
        if(dp[i-3] != -1){
            dp[i] = dp[i-3] + 1;
        }
        if(dp[i-5] != -1){
            dp[i] =(dp[i] == -1) ? dp[i-5] + 1 : min(dp[i], dp[i-5] +1);
        }
    }

    cout << dp[n] << endl;

}