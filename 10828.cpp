#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n,r;
    stack<int> arr;
    cin >> n;

    for(int i=0; i<n; i++){
        string cmd;
        int num;

        cin >> cmd;

        if(cmd == "push"){
            cin >> num;
            arr.push(num);
        }
        else if(cmd == "top"){
            if(arr.size() > 0){
                r = arr.top();
            }
            else{
                r = -1;
            }
            cout << r <<"\n";

        }
        else if(cmd == "size"){
            r = arr.size();
            cout << r <<"\n";

        }
        else if(cmd == "empty"){
            if(arr.size() == 0){
                r = 1;
            }
            else{
                r = 0;
            }
            cout << r <<"\n";
        }
        else if(cmd == "pop"){
            if(arr.size()==0){
                r = -1;
                cout << r <<"\n";
            }
            else{
                r = arr.top();
                arr.pop();
                cout << r <<"\n";
            }
        }
    }
}