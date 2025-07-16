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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> ans(n, false);
    int cnt = 0;
    for (int i = n-1; i >= 0; --i) {
        bool flg = false;
        for (int j = i; j < n; j = j + (i+1)) {
            flg ^= ans[j];
        }
        if (flg ^ a[i]) {
            ++cnt;
            ans[i] = true;
        }
    }
    cout << cnt << endl;
    if (cnt == 0) return 0;
    rep(i, n) {
        if (ans[i]) {
            if (i >= 1) cout << " ";
            cout << i+1;
        } 
    }
    cout << endl;
    return 0;
}
