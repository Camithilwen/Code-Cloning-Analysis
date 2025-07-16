#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int count = 0;
    bool flag = true;
    while (flag) {
        rep(i, n) {
            if (v[i] % 2 == 1) {
                flag = false;
                break;
            }
            v[i] /= 2;
        }
        if (flag) count++;
    }
    cout << count << endl;
    return 0;
}