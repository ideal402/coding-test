#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s;
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    // (()[[]])([])
    // (2+3*3)*2 + 2*3
    // 2*2 + 2*3*3 + 2*3

    int ans = 0;
    int temp = 1;
    char pre;

    for(auto c: s){
        if(c == '('){
            v.push_back(c);
            temp *= 2;
        }
        else if(c == '['){
            v.push_back(c);
            temp *= 3;
        }
        else if(c == ')'){
            if(v.empty() || v.back() != '('){
                cout << 0;
                return 0;
            }
            if(pre == '(') ans += temp;
            temp /= 2;
            v.pop_back();
        }
        else{
            if(v.empty() || v.back() != '['){
                cout << 0;
                return 0;
            }
            if(pre == '[') ans += temp;
            temp /= 3;
            v.pop_back();
        }
        pre = c;
    }

    if(!v.empty()){
        cout << 0;
    }
    else{
        cout << ans;
    }

    return 0;
}