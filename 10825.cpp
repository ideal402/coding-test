#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Data
{
    string str;
    int int1, int2, int3;
};

bool sorting(const Data &a, const Data &b){
    if (a.int1 != b.int1)
        return a.int1 > b.int1;
    if (a.int2 != b.int2) 
        return a.int2 < b.int2;
    if(a.int3 != b.int3)
        return a.int3 > b.int3;
    return a.str < b.str;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<Data> array(n);

    cin >> n;

    for(int i=0; i<n; i++){
        Data temp;
        cin >> temp.str >> temp.int1 >> temp.int2 >> temp.int3; 
        array.push_back(temp);
    }


    sort(array.begin(), array.end(), sorting); 

    for (auto x: array){
        cout << x.str << "\n";
    }

    return 0;
}