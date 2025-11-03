#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string a;
vector<char> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        v.clear();

        for(auto x: a){
            if(v.empty()){
                v.push_back(x);
            }
            else if(v.back() != x){
                v.push_back(x);
            }
            else{
                v.pop_back();
            }
        }

        if(v.empty()) ans++;
    }

    cout << ans;
    return 0;
}