#include <iostream>
#include <algorithm>

using namespace std;

string a;
string b;

int dp[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a;
    cin >> b;

    int n = a.length();
    int m = b.length();

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
        }   
    }
    
    cout << dp[n][m];

    return 0;
}