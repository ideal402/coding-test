#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, k;
string cmd;
string arr;
deque<int> dq;

void parse(string& tmp, deque<int>& d){
  int cur = 0;
  for(int i = 1; i+1 < tmp.size(); i++)
  {
    if(tmp[i] == ','){
      d.push_back(cur);
      cur = 0;
    }
    else{
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  if(cur != 0)
    d.push_back(cur);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    for(int i=0; i<k; i++){
        cin >> cmd;
        cin >> n;
        cin >> arr;
        
    
        dq.clear();

        if(n > 0) {
            parse(arr, dq);
        }

        bool isReversed = false;
        bool isError = false;

        for(char c: cmd){

            if(c == 'R'){
                isReversed = !isReversed;
            }
            else{
                if(dq.empty()){
                    isError = true;
                    break;
                }

                if(!isReversed){
                    dq.pop_front();
                }
                else{
                    dq.pop_back();
                }
            }
        }
        
        if(isError){
            cout << "error" << "\n";
        }
        else{
            cout << "[";
            while(!dq.empty()){
                if(!isReversed){
                    cout << dq.front();
                    dq.pop_front();
                }
                else{
                    cout << dq.back();
                    dq.pop_back();    
                }
                if(!dq.empty()) cout << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}