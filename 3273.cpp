#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    
    cin >> n;


    int b[n];

    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    sort(b, b+n);


    cin >> x;
    int ans = 0;
    int s = 0;
    int e = n-1;

    while(s < e){
        if (b[s]+b[e] > x){
            e--;
        }
        else if(b[s]+b[e] == x){
            ans++;
            s++;
        }
        else{
            s++;
        }
    }

    cout << ans;

    return 0;
}