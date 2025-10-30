#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[11];

int main(){
    
    cin >> n;

    a[1] = 1;
    a[2] = 2;
    a[3] = 4;

    for(int i=4; i<11; i++){
        a[i] = a[i-1]+a[i-2]+a[i-3];
    }

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        cout << a[temp] << "\n";
    }

    return 0;
}