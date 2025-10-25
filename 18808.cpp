#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k,a,b;
int board[42][42];
int stic[12][12];

bool check(int x, int y){
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){                
            if(board[x+i][y+j] == 1 && stic[i][j] == 1) 
                return false;
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(stic[i][j] == 1)
                board[x+i][y+i] = 1;
        }
    }
    return true;
}

void rotate(){
    int temp[12][12];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            temp[i][j] = stic[i][j]; 
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            stic[i][j] = temp[b-1-j][i]; 
        }
    }
    swap(a,b);
}


int main(){
    int flag = 0;
    cin >> n >> m >> k;

    while(k--){
        cin >> a >> b;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                cin >> stic[i][j];
            }
        }
        for(int rot = 0; rot < 4; rot++){
            bool is_paste = false;

            for(int x = 0; x < n-a; x++){
                if(is_paste) break;
                for(int y = 0; y < m-b; y++){
                    if(check(x, y)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cnt += board[i][j];
        }
    }
 
    cout << cnt;

    return 0;
}

