#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, temp;
    vector<int> v;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;

        if(temp == 0 && v.size() != 0){
            v.pop_back();
        }
        else{
            v.push_back(temp);
        }
    }
    int ans = 0;

    for(auto x: v){
        ans += x;
    }

    cout << ans;
    
    return 0;
}