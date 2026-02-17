// 마지막 풀이 26.02.13
#include <iostream>
#include <algorithm>

using namespace std;

int ans[11];
int a,b,c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    int sum = a*b*c;

    while (sum > 9)
    {
        int m = sum%10;
        sum = sum/10;
        ans[m]++;
    }
    ans[sum]++;

    for(int i = 0; i <10; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}