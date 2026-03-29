#include <iostream>
#include <algorithm>

using namespace std;

// d[i]는 i 번째 숫자까지 더한값

// d[i] = d[i-1] + n[i];

// d[1] = n[1];

int n, m;
int d[100005];
int c[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    d[1] = c[1];

    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + c[i];
    }

    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;

        cout << d[b] - d[a-1] << "\n";
    }


    return 0;
}