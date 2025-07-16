#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 998244353;
ll fact[5010200];
ll invfact[5010200];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a + mod -b);
}


inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

inline ll pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll perm(ll n, ll k){
    return mul(fact[n], invfact[n-k]);
}

ll comb(ll n, ll k){
    if(k == 0){
        return 1;
    }
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}


int main(){
    ll N, M;
    cin >> N >> M;
    make_fact(5010000);
    make_invfact(5010000);

    ll res = 1;
    res = mul(res, comb(3 * M + N - 1, N-1));

    for(ll i = 2 * M + 1; i <= 3 * M; i++){
        ll remain = 3 * M - i;
        ll tmp = mul(N, comb(N + remain - 2, N-2));
        res = sub(res, tmp);
    }
    for(ll x = M + 1; x <= N; x++){
        if(3 * M - x < 0 || (3 * M - x) % 2 == 1){
            continue;
        }
        if(x > N){
            continue;
        }
        ll ball = (3 * M - x) / 2;

        ll tmp = mul(comb(N, x), comb(ball + N - 1, N-1));
        res = sub(res, tmp);
    }

    cout << res << endl;
}