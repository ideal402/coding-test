#include <iostream>
#include <vector>

using namespace std;

int n;
int ans = 0;
vector<int> used;
vector<int> used_up;
vector<int> used_down;


void check(int k){
    if(k==n){
        ans++;
        return;
    }

    for (int i=0; i<n; i++){
        if(!used[i] && !used_up[i+k] && !used_down[(n-1)+k-i]){
            used[i] = 1;
            used_up[i+k] = 1;
            used_down[(n-1)+k-i] = 1;
            check(k+1);
            used[i] = 0;
            used_up[i+k] = 0;
            used_down[(n-1)+k-i] = 0;
        }
    }
}

int main(){
    cin >> n;

    used.resize(n, 0);
    used_up.resize((n * 2) + 1, 0);
    used_down.resize((n * 2) + 1, 0);
    
    check(0);
    cout << ans;

    return 0;
}