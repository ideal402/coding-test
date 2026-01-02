#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool comp(string s1, string s2){
    return s1 > s2; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, int> m;
    int n;

    cin >> n;

    for(int i = 0; i<n; i++){
        string temp, temp2;
        cin >> temp >> temp2;
        if(temp2 == "enter"){
            m[temp] = 1;
        }
        else m.erase(temp);
    }

    string arr[m.size()];
    int idx = 0;

    for(auto e : m){
        arr[idx++] = e.first;
    }
    
    sort(arr, arr+m.size(), comp);

    for(auto x: arr){
        cout << x << "\n";
    }

    return 0;
}