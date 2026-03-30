#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int n, m;
string name[1005];
unordered_map<string,int> id;

int arr[1005];
vector<int> adj[1005];
vector<string> sons[1005];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> name[i];
    }

    sort(name, name+n);

    for(int i = 0; i < n; i++){
        id[name[i]] = i;
    }

    cin >> m;

    for(int i = 0; i < m; i++){
        string temp1, temp2;
        cin >> temp1 >> temp2;

        arr[id[temp1]]++;
        adj[id[temp2]].push_back(id[temp1]);
    }


    queue<int> q;
    vector<string> ans_name;

    for(int i = 0; i < n; i++){
        if(arr[i] == 0) {
            q.push(i);
            ans_name.push_back(name[i]);
        }
    }

    while (!q.empty()){
        int cur = q.front(); q.pop();

        for(auto nxt: adj[cur]){
            if(--arr[nxt] == 0) {
                q.push(nxt);
                sons[cur].push_back(name[nxt]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        sort(sons[i].begin(), sons[i].end());
    }

    cout << ans_name.size() << "\n";
    for(auto x: ans_name){
        cout << x << " ";
    }
    cout << "\n";
    
    for(int i = 0; i < n; i++){
        cout << name[i] << " ";
        cout << sons[i].size() << " ";
        for(auto x: sons[i]){
            cout << x << " ";
        }  
        cout << "\n";
    }

    return 0;
}