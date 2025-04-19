#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, num; 
    vector<int> v;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> num;

        if (num==0){
            if(v.size()==0){
                cout << "0" << "\n";
            }
            else{
                pop_heap(v.begin(), v.end());
                cout << v.back()<<"\n";
                v.pop_back();
            }
        }  
        else{
            v.push_back(num);
            push_heap(v.begin(), v.end());
        }
    }
}