#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<char> a;
    int ans = 0;
    int temp = 1;
    char b=0;
    string n;

    cin >> n;

    for(char x: n){
        if(x=='('){
            a.push(x);
            temp *= 2;
        }
        else if(x == '['){
            a.push(x);
            temp *= 3;
        }
        else if(x == ')'){
            if(a.empty() || a.top() != '('){
                cout << 0;
                return 0;
            }
            if(b == '('){
                ans += temp;
            }
            a.pop();
            temp /= 2;
        }
        else{
            if(a.empty() || a.top() != '['){
                cout << 0;
                return 0;
            }
            if(b == '['){
                ans += temp;
            }
            a.pop();
            temp /= 3;
        }
        b = x;
    }
    if(!a.empty()){
        cout << 0;
    }
    else{
        cout << ans;
    }   
    return 0;
}
