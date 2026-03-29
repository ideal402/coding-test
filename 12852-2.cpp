#include <iostream>
#include <algorithm>

using namespace std;

// d[i][j] i번째 수를 만들 수 있는 최소 횟수 j = 0은 횟수 j=1 이전 값의 인덱스 번호

// d[i][0] = min(d[i-1][0]) + 1
// d[i][1] = i-1;
// if(i%2 == 0) {
//     if(d[i][0] > d[i/2][0]){
//         d[i][0] = d[i/2][0];
//         d[i][1] = i/2;
//     }
// }
// if(i%3 == 0) {
//     if(d[i][0] > d[i/3][0]){
//         d[i][0] = d[i/3][0];
//         d[i][1] = i/3;
//     }
// }

// d[1][0] = 1;
// d[1][1] = 1;

int n;
int d[1000005][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1][0] = 0;
    d[1][1] = 1;

    cin >> n;

    for(int i = 2; i <= n; i++){
        d[i][0] = d[i-1][0] + 1;
        d[i][1] = i-1;
        if(i%2 == 0) {
            if(d[i][0] > d[i/2][0] + 1){
                d[i][0] = d[i/2][0] + 1;
                d[i][1] = i/2;
            }
        }
        if(i%3 == 0) {
            if(d[i][0] > d[i/3][0] + 1){
                d[i][0] = d[i/3][0] + 1;
                d[i][1] = i/3;
            }
        }
    }

    cout << d[n][0] << "\n";
    
    int i = n;

    while(i != 1){
        cout << i << " ";
        i = d[i][1];
    }
    cout << i;

    return 0;
}