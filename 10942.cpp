#include <iostream>
#include <algorithm>

using namespace std;

// d[i][j] 는 i부터 j까지 펠린드롭의 여부

// d[i][j] = d[i-1][j-1] && board[i-1][j] == board[i][j-1] ? 1 : 0;

// d[i][i] = 1;
// d[i][i+1] = d[i][i] == d[i][i+1] ? 1 : 0;

int n;
int a[2005];
int d[2005][2005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];    
    }

    for(int i = 1; i <= n; i++){
        d[i][i] = 1;
        if(a[i] == a[i+1]) d[i][i+1] = 1;
    }

    for(int len = 3; len <= n; len++){
        for(int i = 1; i <= n-len+1; i++){
            int j = i+len-1;

            if(a[i] == a[j] && d[i+1][j-1] == 1){
                d[i][j] = 1;
            }
        }
    }

    int t;

    cin >> t;
    while(t--){
        int s, e;
        cin >> s >> e;
        cout << d[s][e] << "\n";
    }

    return 0;
}