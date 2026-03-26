#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
set<pair<int, string>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    string temp;

    for(int i = 0; i < n; i++){
        cin >> temp;
        s.insert({temp.size(),temp});
    }

    for(auto x: s){
        cout << x.second <<"\n";
    }

    return 0;
}