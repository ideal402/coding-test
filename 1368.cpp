#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int p[304];

priority_queue<tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq; 


int my_find(int a){
    if(p[a] == a) return a;
    return p[a] = my_find(p[a]);
}

bool my_union(int a, int b){
    int root_a = my_find(a);
    int root_b = my_find(b);

    if(root_a != root_b){
        p[root_a] = root_b;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n+1; i++){
        p[i] = i;   
    }

    int cost, a, b;

    for(int i = 1; i < n+1; i++){    
        cin >> cost;
        pq.push(make_tuple(cost, 0, i));
    }
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cin >> cost;
            if(i < j) pq.push(make_tuple(cost, i, j));
        }
    }

    int cnt = 0;
    int ans = 0;

    while(!pq.empty() && cnt < n){
        tie(cost, a, b) =  pq.top();
        pq.pop();

        if(my_union(a,b)){
            ans += cost;
            cnt++;
        };
    }

    cout << ans;

    return 0;
}