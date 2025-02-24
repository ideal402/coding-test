#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    string name;
    int age;
};

bool sorting(const Data &a, const Data &b) {
    return a.age < b.age;
}

int main(){

    int n;
    vector<Data> array;
    cin >> n;

    for(int i=0; i<n; i++){
        Data temp;
        cin >> temp.age >> temp.name;

        array.push_back(temp);
    }

    stable_sort(array.begin(), array.end(), sorting);

    for(auto x: array){
        cout << x.age << " " << x.name <<"\n";
    }
}