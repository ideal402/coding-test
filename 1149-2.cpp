#include <iostream>
#include <algorithm>

using namespace std;

// 테이블
// d[i][j] = i번쨰 집을 j번째 색으로 칠할때 최소값

// 점화식
// d[i][0] = min(d[i-1][1], d[i-1][2]) + c[i][0];
// d[i][1] = min(d[i-1][2], d[i-1][0]) + c[i][1];
// d[i][2] = min(d[i-1][0], d[i-1][1]) + c[i][2];

// 초기값
// d[1][0] = c[1][0];
// d[1][1] = c[1][1];
// d[1][2] = c[1][2];

int n;
int d[1005][3];
int c[1005][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }

    d[1][0] = c[1][0];
    d[1][1] = c[1][1];
    d[1][2] = c[1][2];
    
    for(int i = 2; i <= n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + c[i][0];
        d[i][1] = min(d[i-1][2], d[i-1][0]) + c[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + c[i][2];
    }

    cout << min({d[n][0], d[n][1], d[n][2]});

    
    return 0;
}