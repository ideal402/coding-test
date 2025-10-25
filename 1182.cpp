#include <iostream>

using namespace std;
int n, s;
int arr[20];
int isused[20];
int ans = 0;

void func(int k, int sum){

    if(k==n){
        if(sum == s){
            ans++;
        }
        return;
    }

    func(k+1, sum + arr[k]);
    func(k+1, sum);
}

int main(){
    cin >> n >> s;

    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    func(0,0);

    if(s==0){
        ans--;
    }
    
    cout << ans;
}