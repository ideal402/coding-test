#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> table[100004];

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> table[i].second >> table[i].first;
    }

    sort(table, table+n);

    int cnt = 0;
    int t = 0;

    for(int i = 0; i<n; i++){
        if(t > table[i].second) continue;
        cnt++;
        t = table[i].first;
    }

    cout << cnt;
}