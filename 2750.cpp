#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> array;

    cin >> n;
    
    for (int i = 0; i < n; i++){
        int temp;

        cin >> temp;

        array.push_back(temp);

    }

    sort(array.begin(), array.end());

    for(auto x: array){
        cout << x << endl;
    }

    return 0;
}