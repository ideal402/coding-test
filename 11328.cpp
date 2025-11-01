#include <iostream>

using namespace std;

int n;
string a, b;

bool check(){
    int a_arr[26] = {0};
    int b_arr[26] = {0};

    for(char c: a){
        a_arr[c-'a']++;
    }
    for(char c: b){
        b_arr[c-'a']++;
    }
    for(int i=0; i<26; i++){
        if(a_arr[i] != b_arr[i]) return false;
    }

    return true;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(check()) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    
    return 0;
}