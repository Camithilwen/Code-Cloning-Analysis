//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <complex>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;

[[maybe_unused]] constexpr ll LL_MAX = numeric_limits<ll>::max();
[[maybe_unused]] constexpr ll LL_MIN = numeric_limits<ll>::min();
[[maybe_unused]] constexpr ull ULL_MAX = numeric_limits<ull>::max();

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

template <typename T>
void chmin(T& x, T y) {
    x = min(x, y);
}

template <typename T>
void chmax(T& x, T y) {
    x = max(x, y);
}

ll csum(ll x, ll y) {
    if (x > 0 && y > 0 && x > LL_MAX - y) {
        return LL_MAX;
    }
    if (x < 0 && y < 0 && x < LL_MIN - y) {
        return LL_MIN;
    }
    return x + y;
}

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,0,N) {
        cin >> A[i];
    }
    rep(k,0,K) {
        vector<ll> diff(N+1);
        rep(i,0,N) {
            ll add = i - A[i];
            ll subtract = i + 1 + A[i];
            auto clamp = [N](ll x){
                return min(N, max((ll)0, x));
            };
            add = clamp(add);
            subtract = clamp(subtract);
            diff[add] += 1;
            diff[subtract] -= 1;
        }
        ll val = 0;
        bool all_N = true;
        rep(i,0,N) {
            val += diff[i];
            A[i] = val;
            if (A[i] != N) {
                all_N = false;
            }
        }
        if (all_N) {
            break;
        }
    }
    rep(i,0,N) {
        cout << A[i];
        if (i != N-1) {
            cout << " ";
        }
    }
    cout << endl;
}

/*
 
 6 100
 0 0 0 0 0 0 0
 
 */
