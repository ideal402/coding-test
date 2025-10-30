#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[1005][3];
int dp[1005][3];

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> map[i][j];
        }
    }

    int ans = 0;
    int temp;

    dp[1][0] = map[1][0];
    dp[1][1] = map[1][1];
    dp[1][2] = map[1][2];
    
    for(int i=2; i<=n; i++){ 
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + map[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + map[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + map[i][2];
    }
    
    
    cout << min(dp[n][0], min(dp[n][1],dp[n][2]));

    return 0;
}