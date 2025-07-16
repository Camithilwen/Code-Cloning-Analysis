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
    ll n, m;
    cin >> n >> m;
    if (m % n == 0) {
        cout << m / n << endl;
        return 0;
    }
    for (ll i = m / n; i >= 1; --i) {
        if (m % i != 0) continue;
        ll rest = m - i * n;
        if (rest < 0) continue;
        if (rest % i == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
