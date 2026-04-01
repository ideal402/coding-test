#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> f[100005];

bool comp(const pair<int, int>& a, const pair<int, int> &b){
    if (a.second == b.second) {
        return a.first > b.first; 
    }
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        f[i] = {sm*100+sd, em*100+ed};
    }

    sort(f, f+n, comp);

    int cur = 301;
    int end = 1201;
    int ans = 0;
    
    while (cur < end){
        int next = cur; 
        for(int i = 0; i < n; i++){
            if(f[i].first <= cur && f[i].second > next) {
                next = f[i].second; 
            }
        }
        if(next == cur){
            cout << 0;
            return 0;
        }
        ans++;
        cur = next;
    }
    
    cout << ans;


    return 0;
}