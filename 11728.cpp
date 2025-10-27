#include <iostream>

using namespace std;

int n, m;
int a[1000005], b[10000005], c[20000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    int idx_a = 0, idx_b=0;

    for(int i=0; i<n+m; i++)
    {   
        if(idx_a == n) c[i] = b[idx_b++];
        else if(idx_b == m) c[i] = a[idx_a++];
        else if(a[idx_a] <= b[idx_b]){
            c[i] = a[idx_a++];
        }
        else{
            c[i] = b[idx_b++];
        }
    }
    
    for(int i=0; i<n+m; i++) cout << c[i] << " ";

    return 0;
}