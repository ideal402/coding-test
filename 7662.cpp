#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, k;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> k;

        char cmd;
        int num;
        multiset<int> arr;

        for(int j = 0; j<k; j++){
            cin >> cmd;
            cin >> num;

            if (cmd == 'I'){
                arr.insert(num);
            }
            else{
                if (arr.empty()) continue;

                if (num == -1){
                    arr.erase(arr.begin());
                }
                else{
                    arr.erase(prev(arr.end()));
                }
            }
        }

        if(arr.empty()) cout << "EMPTY\n";
        else {
            cout <<  *prev(arr.end())  << " " << *arr.begin() <<"\n";
        }
    }


    return 0; 
}