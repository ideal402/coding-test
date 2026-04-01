#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<int> t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        t.push_back(temp);
    }

    sort(t.begin(), t.end());

    int cur_t = 0;
    int total = 0;

    for(auto x: t){
        total += cur_t+x;
        cur_t += x;
    }

    cout << total;


    return 0;
}
 