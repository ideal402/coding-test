#include <iostream>
#include <algorithm>

using namespace std;

// d[i][0] i 번째 피보나치 함수가 0을 출력한 횟수
// d[1][1] i 번째 함수가 1을 출력한 횟수

// d[i][0] = d[i-1][0]+d[i-2][0];
// d[i][1] = d[i-1][1]+d[i-2][1];

// d[0][0] = 1;
// d[0][1] = 0;
// d[1][0] = 0;
// d[1][1] = 1;

int t, n;
int d[45][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;

    for(int i = 2; i <= 40; i++){
        d[i][0] = d[i-1][0]+d[i-2][0];
        d[i][1] = d[i-1][1]+d[i-2][1];
    }
    
    cin >> t;

    while(t--){
        cin >> n;
        cout << d[n][0] << " " << d[n][1] << "\n";
    }

    return 0;
}