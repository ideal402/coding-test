#include <iostream>
#include <vector>

using namespace std;

int k;

vector<int> arr;

int main(){

    cin >> k;

    for(int i=0; i<k; i++){
        int temp;
        cin >> temp;

        if(temp == 0 && arr.size() != 0){
            arr.pop_back();
        }
        else{
            arr.push_back(temp);
        }
    }
    int ans = 0;

    for(int x: arr){
        ans += x;
    }

    cout << ans;
    return 0;
}