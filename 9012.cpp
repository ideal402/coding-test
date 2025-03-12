#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n,temp;
    string a;
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a;
        temp = 0;
        for(auto c:a){
            if(c == '('){
                temp += 1;
            }
            else{
                temp -= 1;
            }
            if(temp < 0) break;
        } 
        if (temp == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}