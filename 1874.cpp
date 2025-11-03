#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> a;
vector<int> b;

int main(){
    cin >> k;
    string ans;
    int cnt = 1;

    for(int i = 0; i<k; i++){
        int temp;
        cin >> temp;

        while(a.empty() || a.back() != temp)
        {
            if(cnt > k){
                cout << "NO";
                return 0;
            }
            a.push_back(cnt++);
            ans.append("+\n");
        }

        if(a.back() == temp){
            a.pop_back();
            ans.append("-\n");
        }
    }

    cout << ans;

    return 0;
}
