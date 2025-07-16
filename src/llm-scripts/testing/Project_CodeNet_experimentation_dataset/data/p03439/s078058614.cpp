#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;
const double PI = acos(-1);

int N;
string a0;

string ask(int i) {
    out(i);
    fflush(stdout);
    
    string res; 
    cin >> res;
    return res;
}

void f(int l, int r) {
    int md = (l + r) / 2;

    string res = ask(md);
    if (res == "Vacant") return;

    if ((md % 2 == 0 && a0 == res) 
        || (md % 2 == 1 && a0 != res)) {
        f(md + 1, r);
    }
    else {
        f(l, md);
    }
}

int main() {
    cin >> N;

    a0 = ask(0);
    if (a0 == "Vacant") return 0;

    f(1, N);

    return 0;
}