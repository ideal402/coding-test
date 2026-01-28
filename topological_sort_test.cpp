#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int in_degree[7] = {0, 3, 0, 1, 2, 1, 0};
vector<int> adj[7] = {{1},{},{1,3},{1,4},{5},{},{4}}; 

queue<int> q;
vector<int> result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 7; i++){
        if (in_degree[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur+1);

        for(auto next: adj[cur]){
            if(--in_degree[next] == 0) q.push(next);
        }
    }

    if(result.size() != 7){
        cout << "cycle exsist";
    }
    else{
        for(auto x: result){
            cout << x << " ";
        }
    }

    return 0;
}