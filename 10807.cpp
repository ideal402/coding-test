#include <iostream>

using namespace std;

int n, v;
int arr[202];

int main(){

    cin >> n;

    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        arr[temp+100]++;
    }
    cin >> v;

    cout << arr[v+100];

    return 0;
}