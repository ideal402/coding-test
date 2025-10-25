#include <iostream>

using namespace std;

int a, b, c;


long long test(int a, int b, int c){
    if(b == 1) return a % c;
    
    long long val = test(a, b/2, c);

    val = val * val % c;
    if(b%2 == 0){
        return val;
    }
    else{
        return val * a % c;
    }
}
int main(){
    cin >> a >> b >> c;

    int val = test(a, b, c);
    cout << val;
}