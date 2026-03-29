#include <iostream>
#include <algorithm>

using namespace std;

// 백트래킹으로 풀 때 O(2^n) 시간 초과 -> dp

// d[i][j]는 i번째 줄에서 j번쨰 수를 고를 떄 최대값

// d[i][j] = max(d[i-1][j-1], d[i-1][j]) + c[i][j];
// if(j==i) d[i][j] = d[i-1][j-1] + c[i][j];

// d[1][1] = c[1][1];

int n;
int d[505][505];
int c[505][505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> c[i][j];
        }
    }

    d[1][1] = c[1][1];
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j==i) d[i][j] = d[i-1][j-1] + c[i][j];
            else d[i][j] = max(d[i-1][j-1], d[i-1][j]) + c[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        ans = max(ans, d[n][i]);
    }

    cout << ans;

    return 0;
}