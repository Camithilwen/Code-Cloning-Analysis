#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>
#include <bitset>
#include <sstream>
#include <cassert>
#include <time.h>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}
void printvec (vec &v) {
    Rep (i, (ll)v.size()) {
        cout << v[i] << " \n"[i+1 == (ll)v.size()];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vec A(N);
    Rep (i, N) {
        cin >> A[i];
    }

    ll ans = 0;
    Rep (i, 60) {
        ll cnt = 0;
        Rep (j, N) {
            if ((A[j] >> i) & 1) {
                cnt++;
            }
        }

        if (cnt % 2 == 1) {
            // cout << "i=" << i << "\n";
            ans += (1LL << i);
            Rep (j, N) {
                A[j] &= ~(1LL << i);
            }
        }
    }

    // printvec(A);

    vec basis;
    for (ll e : A) {
        for (ll b : basis) {
            chmin(e, e ^ b);
        }
        if (e) {
            basis.push_back(e);
        }
    }
    
    sort(basis.begin(), basis.end());

    ll n = basis.size();
    Rep (i, n) {
        Rep (j, n) {
            if (i == j) continue;
            chmin(basis[j], basis[j] ^ basis[i]);
        }
    }

    // printvec(basis);

    ll tmp = 0;
    for (ll e : basis) {
        tmp = tmp ^ e;
    }

    ans += 2 * tmp;
    cout << ans << "\n";

    // for (ll i = n-1; i >= 0; i--) {
    //     ans += 2 * basis[i];
    //     for (ll digit = 59; digit >= 0; digit--) {
    //         if (basis[i] >> digit & 1) {
    //             for (ll j = i-1; j >= 0; j--) {
    //                 if (basis[j] >> digit & 1) basis[j] = 0;
    //             }
    //         }
    //     }
    // }

    // cout << ans << "\n";

}