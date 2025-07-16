#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<char>> ans;
    for (int i = 0; i < 50; i++) ans.push_back(vector<char>(100, '#'));
    for (int i = 0; i < 50; i++) ans.push_back(vector<char>(100, '.'));

    a--, b--;
    for (int i = 0; a > 0; i += 2) {
        for (int j = 0; j < 100 && a > 0; j += 2, a--) {
            ans[i][j] = '.';
        }
    }
    for (int i = 51; b > 0; i += 2) {
        for (int j = 0; j < 100 && b > 0; j += 2, b--) {
            ans[i][j] = '#';
        }
    }

    cout << 100 << " " << 100 << endl;
    for (auto e : ans) cout << string(begin(e), end(e)) << endl;
}
