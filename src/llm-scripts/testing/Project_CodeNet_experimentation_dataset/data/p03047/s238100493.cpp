#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using vc = vector<char>;
using pll = pair<ll, ll>;
template<class T> void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T> void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U> bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U> bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T> bool even(T n) { return ! (n & 1); }
template<class T> bool odd(T n) { return n & 1; }
template<class T> ll rup(T a, T b) { return a % b ? a / b + 1 : a / b; }
template<class T> ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T> ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;
ll intpow(ll a, ll n, ll _mod=numeric_limits<ll>::max()) { ll p=1; while (n) { if (n&1) p=p*a%_mod; a=a*a%_mod; n>>=1; } return p; } 
ll modc(ll a, char op, ll b, ll _mod=mod) { a %= _mod; b %= _mod; ll res = 1; switch(op) {
        case '+': res = (a + b) % _mod; break;
        case '-': res = (a - b) % _mod; break;
        case '*': res = a * b % _mod; break;
        case '/': res = modc(a, '*', modc(b, '^', _mod-2, _mod), _mod); break;
        case '^': res = intpow(a, b, _mod); break;
        case 'P': rep(i, a-b+1, a+1) res = modc(res, '*', i, _mod); break;
        case 'C': res = modc(modc(a, 'P', b, _mod), '/', modc(b, 'P', b, _mod)); break; } if (res < 0) res += _mod; return res; }


int main()
{
        ll N, K;
        cin >> N >> K;
        cout << N - K +1 << endl;
}
