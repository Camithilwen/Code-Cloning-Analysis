/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
//ll mod = 1e9 + 7;
//ll MOD = 1e9 + 7;
ll INF = 1e18;

struct RollingHash
{
    typedef long long lint;
    const string str;
    const lint base, mod;
    const V tempvec;
    vector<lint> hash, pw;

    RollingHash(V &s, lint h = 1000000007, lint b = 1009) : tempvec(s), mod(h), base(b)
    {
        int l = s.size();
        hash.assign(l + 1, 0);
        pw.assign(l + 1, 0);
        pw[0] = 1;
        for (int i = 0; i < l; ++i)
        {
            pw[i + 1] = pw[i] * base % mod;
            hash[i + 1] = (hash[i] * base + s[i]) % mod;
        }
    }

    lint const get_hash(int l, int r)
    {
        return ((hash[r] - hash[l] * pw[r - l]) % mod + mod) % mod;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    V Vec1(n);
    rep(i, n) cin >> Vec1[i];
    V Vec2(n);
    rep(i, n) cin >> Vec2[i];
    V vec1(n);
    V vec2(n);
    rep(i, n)
    {
        vec1[i] = Vec1[i] ^ Vec1[(i + 1) % n];
        vec2[i] = Vec2[i] ^ Vec2[(i + 1) % n];
    }
    rep(i,n){
        vec1.push_back(vec1[i]);
    }
    RollingHash tree(vec1, 1e9 + 7, 1e3 + 7);
    RollingHash tree2(vec1, 999999937, 1e3 + 7);
    RollingHash tree5(vec1, 1000000033, 1e3 + 7);
    RollingHash tree3(vec2, 1e9 + 7, 1e3 + 7);
    RollingHash tree4(vec2, 999999937, 1e3 + 7);
    RollingHash tree6(vec2, 1000000033, 1e3 + 7);
    VP res;
    //  cout<<s<<" "<<t<<endl;
    rep(i, n)
    {
        ll s_hash = tree.get_hash(i, i + n);
        ll t_hash = tree3.get_hash(0, n);
        ll s_hash2 = tree2.get_hash(i, i + n);
        ll t_hash2 = tree4.get_hash(0, n);
        ll s_hash3 = tree5.get_hash(i, i + n);
        ll t_hash3 = tree6.get_hash(0, n);
        if (s_hash == t_hash && s_hash2 == t_hash2 && s_hash3 == t_hash3)
        {
            res.push_back({i, Vec1[i] ^ Vec2[0]});
        }
    }
    rep(i, res.size())
    {
        cout << res[i].F << " " << res[i].S << endl;
    }
}
