#include <iostream>
#include <list>

using namespace std;

int n, k;
list<int> arr;

int main(){

    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        arr.push_back(i+1);    
    }

    auto cur = arr.begin();


    cout << "<";

    while(!arr.empty()){
        for(int j=0; j<k-1; j++){
            cur++;
            if(cur == arr.end()) cur = arr.begin();
        }   
        cout << *cur;
        cur = arr.erase(cur);

        if(cur == arr.end() && !arr.empty()){
            cur = arr.begin();
        }

        if(!arr.empty()){
            cout << ", ";
        }

    }

    cout << ">";

    return 0;
}