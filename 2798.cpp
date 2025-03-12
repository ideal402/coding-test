#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    vector<int> arr(n,0);

    cin >> n >> m;
    
    for (int i =0; i<n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    int card;
    int max = 0;
    for (int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                card = arr[i]+arr[j]+arr[k];
                if(card <= m && max < card) max = card;
            }
        }
    }

    cout << max;

    return 0;
}