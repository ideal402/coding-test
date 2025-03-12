#include <iostream>
#include <string>

using namespace std;

bool contain(int num){
    while (num>0){
        if(num%1000 == 666) return true;
        num /= 10;
    }
    return false;
}

int main(){
    int n, num, cnt;
    cin >> n;
    
    cnt = 0;
    num = 666;

    while(cnt < n){
        if (contain(num)){
            cnt++;
        }
        if(cnt < n){
            num++;
        }
    }
    cout << num;
}