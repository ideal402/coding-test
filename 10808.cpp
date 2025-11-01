#include <iostream>

using namespace std;

string s;
int a[26] ;

int main(){
    cin >> s;
    
    for(int i=0; i<s.length(); i++){
        int temp = s[i] - 'a';
        a[temp]++;
    }

    for(auto x: a){
        cout << x << " ";
    }

    return 0;
}