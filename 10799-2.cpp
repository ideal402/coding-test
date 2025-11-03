#include <iostream>
#include <algorithm>

using namespace std;

string s;
vector<char> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int ans = 0;
    int temp = 0;

    for(auto c: s){
        if(c == '(') a.push_back(c);
        else{
            if(temp == '('){
                ans += a.size() - 1;
            }
            else ans++;
            a.pop_back();
        }
        temp = c;
    }

    cout << ans;
    return 0;
}