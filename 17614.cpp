#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int ans = 0;
    cin >> n;

    for (int i=1; i<n+1; i++){
        string s;
        s = to_string(i);

        for(char x: s){
            if(x=='3' || x == '6' || x=='9'){
                ans++;
            }
        }

    }
    cout << ans;
}