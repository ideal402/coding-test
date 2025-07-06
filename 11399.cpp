#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int sum = 0;
    int acc = 0;

    for(int i = 0; i<n; i++){
        acc += arr[i];
        sum += acc;
    }

    cout << sum << "\n";
}
