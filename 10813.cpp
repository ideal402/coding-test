#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){

    int n,m;
    
    cin >> n >> m;
  
    vector<int> arr(n);
    iota(arr.begin(), arr.end(),1);

    for(int i=0; i<m;i++){
        int temp1, temp2;

        cin >> temp1 >> temp2;

        int temp;
        temp = arr[temp2-1];
        arr[temp2-1] = arr[temp1-1];
        arr[temp1-1] = temp;
    }

    for(auto x:arr){
        cout << x << " ";
    }

    return 0;
}