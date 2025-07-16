#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<ll>> vvll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (ll i = (n)-1; i >= 0; --i)
#define mes(a) cout << (a) << endl
#define dmes(a, b) cout << (a) << " " << (b) << endl
#define re0 return 0
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define rSort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
struct io
{
    io()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
};
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-19;







int main() {
    ll n, y;
    cin >> n >> y;
    y /= 1000;
    ll yc = 0;
    
    for (ll i = 0; i < n+1; i++) {
        for(ll j = 0; j < n+1; j++) {
            if (i+j > n) continue;
            yc = 10*i+5*j+(n-(i+j));
            if (yc == y) {
                printf("%lld %lld %lld", i, j, n-(i+j));
                re0;
            }
        }
    }
    
    mes("-1 -1 -1");
    
    
}