#include <iostream>
#include <deque>
#include <numeric>
#include <string>
using namespace std;

int main(){
    int n, k;
    string ans = "<";
    cin >> n >> k;

    deque<int> dq(n);
    
    iota(dq.begin(), dq.end(), 1);
    
    int c, temp;
    c=0;

    while (dq.size()>1)
    {
        c++;
        temp = dq.front();
        
        dq.pop_front();
        if(c%k == 0){
            ans += to_string(temp)+", ";    
        }
        else{
            dq.push_back(temp);
        }
    }

    temp = dq.front();
    ans += to_string(temp)+">";
    
    cout << ans;

}