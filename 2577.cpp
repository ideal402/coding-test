#include <iostream>

using namespace std;


int a, b, c, sum;
int arr[10];

int main(){
    cin >> a >> b >> c;
    sum = a*b*c;

    while(sum>=10){
        arr[sum%10]++;
        sum /= 10;
    }
    arr[sum]++;

    for(int i=0; i<10; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}