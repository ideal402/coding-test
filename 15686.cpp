#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int board[52][52];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i, j});
            if(board[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin()+chicken.size() - m, 0);
    int mn = 0x7f7f7f7f;

    do{
        int dist = 0;
        for(auto h: house){
            int temp = 0x7f7f7f7f;
            for(int i=0; i< chicken.size(); i++){
                if(brute[i] == 0) continue;
                temp = min(temp, abs(chicken[i].first - house[i].first) +abs(chicken[i].second - house[i].second));
            }
            dist += temp;
        }
        mn = min(mn, dist);
    }while (next_permutation(brute.begin(), brute.end()));
    
    
    cout << mn; 

    return 0;
}

// 치킨거리 구하기
// 페업할 치킨집 고르기