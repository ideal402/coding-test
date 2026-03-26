#include <iostream>
#include <algorithm>

using namespace std;

int t, n, goal;
int money[22];
int dp[22][10004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for(int a = 0; a < t; a++){
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> money[i];
            dp[i][0] = 1;
        }

        cin >> goal;


        for(int i = 0; i < n; i++){
            for(int j=1; j <= goal; j++){
                dp[i][j] = 0;
                if(i-1 >= 0)
                    dp[i][j] += dp[i-1][j];
                if(j-money[i] >= 0)
                    dp[i][j] += dp[i][j-money[i]];    
            }
        }

        cout << dp[n-1][goal] << "\n";
    }


    return 0;
}
