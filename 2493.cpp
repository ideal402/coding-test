#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int temp;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;

        while(!a.empty() && a.back().first < temp){
            a.pop_back();
        }

        if(a.empty()){
            cout << 0 << " ";
        }
        else{
            cout << a.back().second << " ";
        }
 
        a.push_back({temp, i+1});

    }

    return 0;
}