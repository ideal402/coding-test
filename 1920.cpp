#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int target;
    int left, right, mid;
    bool flag=false;

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> arr[i]; 
    }

    sort(arr, arr+n);
    
    cin >> m;

    for(int i = 0; i<m; i++){
        left = 0;
        right = n-1;
        flag = 0;

        cin >> target;

        while(left <= right){
            mid = (left + right)/2;

            if(arr[mid] == target){
                flag = 1;
                break;
            }
            else if(arr[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        if(flag){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
}