#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int m, n;

    cin >> m >> n;

    vector<bool> is_prime(n+1, true);

    is_prime[0] = false;
    is_prime[1] = false;
    
    for(int i = 2; i*i <= n; i++){
        if(is_prime[i]){
            for(int j= i*2; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }

    for(int i=m; i <= n; i++){
        if(is_prime[i]) cout << i <<"\n";
    }

    return 0;
}