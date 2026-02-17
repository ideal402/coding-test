#include <iostream>
#include <algorithm>

using namespace std;

// 0 1 => 1 
// 00 01 10 11 => 1
// 000 001 010 011 100 101 110 111 => 2
// 0000 0001 0010 0011 0100 0101 0110 0111 
// 1000 1001 1010 1011 1100 1101 1110 1111 => 3
// 10000 10001 10010 10011 10100 10101 10110 10111 
// 11000 11001 11010 11011 11100 11101 11110 11111 => 5

long long dp[94];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = 0;
    dp[1] = 1;

    cin >> n;
    for(int i = 2; i < n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];

    return 0;
}