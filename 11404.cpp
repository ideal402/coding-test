#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100001

int n, m;
int d[104][104];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        fill(d[i], d[i] + n, INF);    
    }

    for(int i = 0; i < n; i++){
        d[i][i] = 0;
    }

    cin >> m;

    int a, b, cost;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> cost;
        if(d[a-1][b-1] > cost){
            d[a-1][b-1] = cost;
        }
    }

    for(int a = 0; a < n; a++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][j] > d[i][a] + d[a][j]){
                    d[i][j] = d[i][a] + d[a][j];
                }
            }   
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << d[i][j] << " ";   
        }
        cout << "\n";
    }
    return 0;
}