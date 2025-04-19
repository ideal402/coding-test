#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        int a,ans;
        ans = 0;
        cin >> a;

        while (a>=5){
            a /= 5;
            ans += a;
        }

        cout << ans << "\n";
    }

    return 0;
}