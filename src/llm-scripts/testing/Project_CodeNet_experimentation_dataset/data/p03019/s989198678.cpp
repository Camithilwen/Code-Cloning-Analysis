// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;
 
signed main() {
    int N, X; cin >> N >> X;
    vector< tuple<int, int, int> > tups;
    for(int i=0; i<N; i++) {
        int b, l, u; cin >> b >> l >> u;
        tups.emplace_back(b, l, u);
    }
    sort(tups.begin(), tups.end(), [&](auto x, auto y) {
            int xb, xl, xu, yb, yl, yu;
            tie(xb, xl, xu) = x;
            tie(yb, yl, yu) = y;

            int vl = xl * xb + xu * (X - xb);
            int vr = yl * yb + yu * (X - yb);
            return vl > vr;
        });

    int D = 0;
    vector<int> acc(N+1), val(N);
    for(int i=0; i<N; i++) {
        int b, l, u; tie(b, l, u) = tups[i];
        D -= b * l;
        val[i  ] = l * b + u * (X - b);
        acc[i+1] = acc[i] + val[i];
    }

    int ub = X*N, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;

        bool ok = false;
        // 中途半端に選ぶものが i 番目の要素
        int q = mid / X, R = mid % X;
        for(int i=0; i<N; i++) {
            int d = D, r = R;
            int b, l, u; tie(b, l, u) = tups[i];
            d += l * min(r, b);
            r -= min(r, b);
            d += u * r;

            if(i < q) {
                d += acc[q+1] - val[i];
            }
            else {
                d += acc[q];
            }
            ok |= (d >= 0);
        }

        if(ok) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}
