#include <iostream>

using namespace std;

int n;
int dp[1000005][2];

int main(){
    cin >> n;

    fill(&dp[0][0], &dp[n+1][0], n+1);
    
    dp[1][0] = 0;
    dp[1][1] = 0;

    
    for(int i=1; i<n; i++){
        if(i+1<=n && dp[i+1][0] > dp[i][0]+1){
            dp[i+1][0] = dp[i][0]+1;
            dp[i+1][1] = i;
        }
        if(i*3<=n && dp[i*3][0] > dp[i][0]+1){
            dp[i*3][0] = dp[i][0]+1;
            dp[i*3][1] = i;
        }
        if(i*2<=n && dp[i*2][0] > dp[i][0]+1){
            dp[i*2][0] = dp[i][0]+1;
            dp[i*2][1] = i;
        }
    }

    cout << dp[n][0] << "\n";

    cout << n << " ";
    while (dp[n][1] != 0)
    {
        cout << dp[n][1] << " ";
        n = dp[n][1];
    }
    
    return 0;
}