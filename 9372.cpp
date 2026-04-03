#include <iostream>
#include <algorithm>

using namespace std;

int t;
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        cin >> n >> m;
        
        int a, b;
        while(m--) cin >> a >> b;

        cout << (n-1) << "\n";
    }
    return 0;
}