#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> idxToName(n + 1); // 1-based index
    map<string, int> nameToIdx;

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        idxToName[i] = name;
        nameToIdx[name] = i;
    }

    for (int i = 0; i < m; i++) {
        string q;
        cin >> q;

        if (isdigit(q[0])) {
            int idx = stoi(q);
            cout << idxToName[idx] << "\n";
        } else {
            cout << nameToIdx[q] << "\n";
        }
    }
    return 0;
}
