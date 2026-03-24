#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
int b[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int temp;

    cin >> n;

    for(int i = 0; i < n; i++){
        // cin >> temp;
        // a.push_back(temp);
        cin >> b[i];   
    }

    // sort(a.begin(), a.end());
    sort(b, b+n);

    // for(auto x: a){
    //     cout << x << "\n";
    // }
    for(int i = 0; i < n; i++){
        cout << b[i] << "\n";
    }
    return 0;
}