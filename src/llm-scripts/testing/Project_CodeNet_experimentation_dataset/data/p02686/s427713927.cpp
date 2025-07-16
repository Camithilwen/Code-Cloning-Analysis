#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

bool cmp(pii x, pii y) {
    return 1ll * x.first * y.second < 1ll * x.second * y.first;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m = 0;
    pii a[1000006] = {};
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int x = 0, y = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '(') x++;
            else x--;
            y = min(y, x);
        }
        a[i] = {-y, x};
    }
    sort(a, a + n, cmp);
    //for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << '\n';
    for (int i = 0; i < n; i++) {
        if (m < a[i].first) {
            cout << "No";
            return 0;
        }
        m += a[i].second;
    }
    if (m) cout << "No";
    else cout << "Yes";
}
