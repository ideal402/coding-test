#include <iostream>
#include <algorithm>

using namespace std;


// 테이블
// d[i] 는 2xi번쨰 테이블을 채울 수 있는 경우의 수

// 점화식
// i = 1 : 1 => 1
// i = 2 : 1+1, (1+1) => d[1] + 1
// i = 3 : 1+(1+1), 1+1+1, (1+1)+1 => d[2] + d[1] 
// i = 4 : 1+1+(1+1), 1+1+1+1, 1+(1+1)+1, (1+1)+1+1, (1+1)+(1+1) => d[3] + d[2]
// d[i] = d[i-1] + d[i-2];

// 초기값
// d[1] = 1;
// d[2] = 2;

int n;
int d[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1;
    d[2] = 2;

    for(int i = 3; i <= n; i++){
        d[i] = (d[i-1] + d[i-2])%10007;
    }

    cout << d[n];
    
    return 0;
}