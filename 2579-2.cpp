#include <iostream>
#include <algorithm>

using namespace std;


// 테이블
// d[i][1]는 i번째 계단을 연속 1회 밟은 점수
// d[i][2]는 i번째 계단을 연속 2회 밟은 점수

// 점화식
// d[i][1] = max(d[i-2][1], d[i-2][2]) + s[i];
// d[i][2] = d[i-1][1] + s[i];

// 초기값
// d[1][1] = s[1];
// d[1][2] = 0;
// d[2][1] = s[2];
// d[2][2] = s[1]+s[2];

int n; 
int s[304];
int d[304][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
 
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1]+s[2];


    for(int i = 3; i <= n; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + s[i];
        d[i][2] = d[i-1][1] + s[i];
    }

    cout << max(d[n][1], d[n][2]);

    return 0;
}