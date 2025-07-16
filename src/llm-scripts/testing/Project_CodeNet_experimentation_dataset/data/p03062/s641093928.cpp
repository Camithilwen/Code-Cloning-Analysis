#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vll dp1(n + 1, -HIGHINF), dp2(n + 1, -HIGHINF);
    dp1[0] = 0;
    for (int i = 0; i < n; i++) {
        chmax(dp1[i + 1], max(dp1[i] + a[i], dp2[i] - a[i]));
        chmax(dp2[i + 1], max(dp1[i] - a[i], dp2[i] + a[i]));
    }
    // DEBUG_VLL(dp1)
    // DEBUG_VLL(dp2)

    cout << dp1.back() << '\n';
    return 0;
}
