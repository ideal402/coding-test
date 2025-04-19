#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> v(n, 0);

    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    unordered_map<int, int> umap;
    int count = 0; 
    int ans = 0;
    
    for (int i = 0; i < k; i++) {
        if (umap[v[i]] == 0) count++; // 새로운 초밥 종류 추가
        umap[v[i]]++;
    }
    if (umap[c] == 0) count++;
    umap[c]++;

    ans = count;

    for (int i = 1; i < n; i++) {
        int remove_idx = i - 1;       // 제거할 초밥
        int add_idx = (i + k - 1) % n; // 새로 추가할 초밥

        umap[v[remove_idx]]--;
        if (umap[v[remove_idx]] == 0) count--; 

        if (umap[v[add_idx]] == 0) count++; 
        umap[v[add_idx]]++;

        ans = max(ans, count);
    }

    cout << ans;
}