#include <iostream>

using namespace std;

int ans, N, R, C;

int find(int n, int r, int c){
    int half = 1 << (n-1);

    if (n == 0){
        return 0;
    }

    if(r < half && c < half) return find(n-1, r, c);
    if(r < half && c >= half) return half*half + find(n-1, r, c-half);
    if(r >= half && c < half) return half*half*2 +find(n-1, r-half, c);
    return half*half*3 + find(n-1, r-half, c-half);

}

int main(){
    cin >> N >> R >> C;
    ans = 0;
    cout << find(N, R, C);
}