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

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    mat A(N, vec(M));
    Rep (i, N) Rep (j, M) {
        cin >> A[i][j];
        A[i][j]--;
    }

    vector<bool> sports(M, true);
    ll ans = 310;
    Rep (i, M) {
        vec cnt(M, 0);
        Rep (j, N) {
            Rep (k, M) {
                if (sports[A[j][k]]) {
                    cnt[A[j][k]]++;
                    break;
                }
            }
        }

        ll sub = 0;
        ll popular = -1;
        Rep (j, M) {
            if (sub < cnt[j]) popular = j;
            chmax(sub, cnt[j]);
        }
        chmin(ans, sub);
        sports[popular] = false;
    }

    cout << ans << endl;
}