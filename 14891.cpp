#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

deque<int> t[4];
int vis[4];

int k;
int num, dir;

// 7 0 1
// 6 x 2
// 5 4 3
void turn(int n, int dir){
    vis[n] = 1;
    int r, l;

    l = (n-1);
    r = (n+1);


    if(l > -1 && t[n][6] != t[l][2] && vis[l]==0){
        turn(l, -dir);
    }
    
    if( r < 4 && t[n][2] != t[r][6] && vis[r]==0){
        turn(r, -dir);
    }

    if(dir == -1){
        int temp = t[n].front();
        t[n].push_back(temp);
        t[n].pop_front();
    }
    else{
        int temp = t[n].back();
        t[n].push_front(temp);
        t[n].pop_back();
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; i++){
        string temp;
        cin >> temp;

        for(int j = 0; j < 8; j++){
            t[i].push_back((temp[j])-'0');
        }
    }

    cin >> k;

    while(k--){
        cin >> num >> dir;
        fill(vis, vis+4, 0);

        turn(num-1, dir);
    }


    int ans = 0;

    for(int i = 0; i < 4; i++){
        if(t[i].front() == 1){
            ans += pow(2,i);
        }
    }

    cout << int(ans);

    return 0;
}