//최종 풀이 26.02.16
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<int> a;
    
    cin >> n >> k;

    for(int i = 1; i < n+1; i++){
        a.push_back(i);
    }

    auto idx = a.begin();

    cout << "<";
    while(!a.empty()){

        for(int i = 0; i < k-1; i++){
            idx++;
            if(idx == a.end()) idx = a.begin();
        }
        cout << *idx ;

        idx = a.erase(idx);

        if(idx == a.end()) idx = a.begin();
        
        if(!a.empty()) cout << ", ";
    }
    cout << ">";

    return 0;
}