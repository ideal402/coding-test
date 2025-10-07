#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string cmd;       
    int dat[10001];
    int head = 0;
    int tail = 0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> cmd;

        if (cmd == "push") {
            int temp;
            cin >> temp;

            dat[tail++] = temp;
        }
        else if(cmd=="front"){
            if(tail != head){
                cout << dat[head] <<"\n";
            }
            else cout << -1 << "\n";
        }
        else if(cmd=="back"){
            if(tail != head){
                cout << dat[tail-1] << "\n";
            }
            else cout << -1 << "\n";
        }
        else if(cmd=="size"){
            cout << tail-head << "\n";
        }
        else if(cmd=="empty"){
            if(tail - head > 0){
                cout << 0 << "\n";
            }
            else cout << 1 << "\n";
        }
        else if(cmd == "pop"){
            if(head < tail){
                cout << dat[head] << "\n";
                head++;
            }
            else{
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}