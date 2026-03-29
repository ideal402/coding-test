#include <iostream>
#include <algorithm>

using namespace std;


// 테이블 정하기
// d[i]는 i를 나타낼 수 있는 경우의 수
// 점화식 세우기
// d[i] = d[i-1] + d[i-2] + d[i-3];
// 초기값 설정
// d[1] = 1, d[2] = 2, d[3] = 4

int t,n;
int d[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i < 11; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    cin >>t;

    while(t--){
        cin >> n;
        cout << d[n] << "\n";
    }

    return 0;
}