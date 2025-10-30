#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int n;
vector<string> a;

bool cmp(const string& a, const string& b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    
    int s_a=0, s_b=0;
    
    for(auto x: a){
        if(isdigit(x)) s_a += x-'0';
    }
    for(auto x: b){
        if(isdigit(x)) s_b += x-'0';
    }
    
    if(s_a != s_b) return s_a < s_b;
    
    return a < b;
    
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        a.push_back(temp); 
    }

    sort(a.begin(), a.end(), cmp);

    for(int i=0; i<n; i++){
        cout << a[i] << "\n";
    }  
}