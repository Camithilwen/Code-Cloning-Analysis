#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = n;
    rep(i, n) {
        bool ok = true;
        rep(j, n - i) {
            if (s[i+j] != t[j]) {
                ok = false;
            }
        }
        if (ok) {
            cout << ans << endl;
            return 0;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
