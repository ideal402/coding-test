#include <iostream>
#include <algorithm>

using namespace std;

// 테이블정의
// dp[i]는 i를 만들기 위한 연산의 최소값
// 점화식
// dp[i] = min(dp[i+1], dp[i*2], dp[i*3]) + 1
// 초가값정하기
// dp[1] = 1

int n;
int dp[1000003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1] = 0;
    
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0) dp[i] = min(dp[i/2]+1 , dp[i]);
        if(i%3 == 0) dp[i] = min(dp[i/3]+1 , dp[i]);
    }

    cout << dp[n];

    return 0;
}