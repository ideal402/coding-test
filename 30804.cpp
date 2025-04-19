#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int left = 0;
    int ans = 0;
    unordered_map<int ,int> check;

    for (int right=0; right<n; right++){
        check[arr[right]]++;

        while (check.size()>2){
            check[arr[left]]--;

            if (check[arr[left]] == 0){
                check.erase(arr[left]);
            }
            left++;
        }

        ans = max(ans, right-left+1);
    }

    cout << ans;
    return 0;
}