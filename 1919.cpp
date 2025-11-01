#include <iostream>

using namespace std;

string a, b;

int check(){
    int a_arr[26] = {0};
    int b_arr[26] = {0};
    int ans = 0;

    for(char c: a){
        a_arr[c-'a']++;
    }
    for(char c: b){
        b_arr[c-'a']++;
    }
    for(int i=0; i<26; i++){
        ans += abs(a_arr[i] - b_arr[i]);
    }

    return ans;
}

int main(){
    cin >> a >> b;
    cout << check();

    return 0;
}