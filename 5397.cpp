#include <iostream>
#include <list>

using namespace std;

int n;
list<char> l;
string init;

int main(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> init;
        
        l.clear();
        auto curser = l.end();

        for(char c: init){
            if(c=='<'){
                if(curser != l.begin()) curser--;
            }
            else if(c=='>'){
                if(curser != l.end()) curser++;
            }
            else if(c=='-'){
                if(curser != l.begin()){
                    curser--;
                    curser = l.erase(curser);
                }
            }
            else{
                l.insert(curser, c);
            }
        }

        for(auto x: l){
            cout << x;
        }
        cout <<"\n";
    }

    return 0;
}