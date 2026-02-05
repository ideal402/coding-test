#include <iostream>
#include <algorithm>


using namespace std;

int const ROOT = 1;
int const MX  = 10000 * 500 + 5;
int unused = 2;
bool check[MX];
int nxt[MX][26];

int n, m;

int c2i(char c){
    return c-'a';
}

void insert(string s){
    int cur = ROOT;
    for(auto c: s){
        if(nxt[cur][c2i(c)]==-1){
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    check[cur] = true;
}

bool find(string s){
    int cur = ROOT;
    for(auto c: s){
        if(nxt[cur][c2i(c)] == -1){
            return false;
        }
        cur = nxt[cur][c2i(c)];
    }
    return check[cur];
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0);


    cin >> n >> m;

    string s;

    for(int i = 0; i < MX; i++){
        fill(nxt[i], nxt[i]+26, -1);
    }

    for(int i = 0; i < n; i++){
        cin >> s;
        insert(s);
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        cin >> s;
        if(find(s)){
            ans++;
        }
    }

    cout << ans;

    return 0;
}