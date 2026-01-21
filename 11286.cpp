#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        else{
            return a.second > b.second;
        }
    }
};

int main() {
    int n, temp;
    
    priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> temp;
        if (temp == 0){
            if(pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top().first << "\n";
                pq.pop();
            }
        }
        else{
            pq.push({temp, abs(temp)});
        }

    }

    return 0;
}
