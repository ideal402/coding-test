#include <iostream>

using namespace std;

int n;
int ans = 0;
int isused1[40];
int isused2[40];
int isused3[40];

void check(int k){
    if(k == n){
        ans++;
        return;
    }

    for(int i=0; i<n; i++){
        if(isused1[i] || isused2[i+k] || isused3[i-k+n-1]) continue;

        isused1[i] = 1;
        isused2[i+k] = 1;
        isused3[i-k+n-1] = 1;
        check(k+1);
        isused1[i] = 0;
        isused2[i+k] = 0;
        isused3[i-k+n-1] = 0;
    }

}

int main(){
    cin >> n;

    check(0);
    cout << ans;

    return 0;
}