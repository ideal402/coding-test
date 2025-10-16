#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s;
    string a;

    cin >> a;
    int ans=0;
    char temp;

    for(char x: a){
        if(x == '('){
            s.push(x);
        }
        else{
            if(temp=='('){
                s.pop();
                ans += s.size();
            }
            else{
                s.pop();
                ans += 1;
            }
        }
        temp = x;
    }
    cout << ans;
    return 0;
}