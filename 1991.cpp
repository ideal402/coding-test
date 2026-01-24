#include <iostream>
#include <algorithm>

using namespace std;

char lc[27];
char rc[27];
char adj[27];

void pre(int root){
    
    cout << adj[root];
    if(lc[root] != '.') pre(lc[root] - 'A' +1);
    if(rc[root] != '.') pre(rc[root] - 'A' +1);
}

void in(int root){
    
    if(lc[root] != '.') in(lc[root] - 'A' +1);
    cout << adj[root];
    if(rc[root] != '.') in(rc[root] - 'A' +1);
}

void post(int root){
    
    if(lc[root] != '.') post(lc[root] - 'A' +1);
    if(rc[root] != '.') post(rc[root] - 'A' +1);
    cout << adj[root];

}

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    char root_name, l_name, r_name;

    for(int i = 0; i < n; i++){
        cin >> root_name >> l_name >> r_name;

        int idx = root_name - 'A' + 1;

        adj[idx] = root_name;
        lc[idx] = l_name;
        rc[idx] = r_name;
    }

    pre(1);
    cout << "\n";
    in(1);
    cout << "\n";
    post(1);

    return 0;
}