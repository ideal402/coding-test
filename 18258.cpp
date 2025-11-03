#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
queue<int> q; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string temp;

    for(int i=0; i<n; i++){
        cin >> temp;

        if(temp == "push"){
            int num;
            cin >> num;
            q.push(num);
        }
        else if(temp == "pop"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(temp == "front"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else cout << q.front() << "\n";
        }
        else if(temp == "back"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else cout << q.back() << "\n";
        }
        else if(temp == "size"){
            cout << q.size() << "\n";
        }
        else if(temp == "empty"){
            if(q.empty()){
                cout << 1 << "\n";
            }
            else cout << 0 << "\n";
        }   
    }

    return 0;
}