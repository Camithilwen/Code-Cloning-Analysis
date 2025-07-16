//vec[i]の範囲外エラー表示
#define _GLIBCXX_DEBUG
//includeとusing
#include <bits/stdc++.h>
using namespace std;
//型名省略
using ll = long long;
using st = string;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using pcc = pair<char, char>;
//定数
const ll INF = 1e9;
const ll MOD = 1e9+7;
const vl dx = {1,0,-1,0,1,0,-1,0};
const vl dy = {0,1,0,-1,0,1,0,-1};
//マクロ
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define rrep(i,n) for(ll i = (ll) n - 1; i >= 0;i--)
#define REP(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define RREP(i,x,n) for(ll i = (ll) n - 1; i >= x; i--)
#define each(i,A) for(ll i: (vl) A)
#define all(A) A.begin(), A.end()
#define Size(A) ll(A.size())
//入力
template<typename T> T input() {T x; cin >> x; return x;}
//正誤判定
void Yes(bool ans){cout << (ans? "Yes" : "No") << endl;}
void YES(bool ans){cout << (ans? "YES" : "NO") << endl;}
//余り切り上げ
ll ceil(ll a,ll b) {return (a + b - 1) / b;}
//最大値・最小値
template <typename T> bool chmax(T &a, const T& b) {if(a < b) {a = b; return true;} return false;}
template <typename T> bool chmin(T &a, const T& b) {if(a > b) {a = b; return true;} return false;}
//最大公約数
ll gcd(ll a,ll b){if(a<b)swap(a,b); if(a%b==0)return b; return gcd(b,a%b);}
//最小公倍数
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//n乗の余り
ll modPow(ll x,ll n,ll mod){if(n==0)return 1; if(n%2==0)return modPow(x*x,n/2,mod)%mod; return x%mod*modPow(x,n-1,mod)%mod;}


/*--------------------------------------------------------------------------*/

//main関数
int main() {
    st s; cin >> s;
    bool flag = false;
    rep(i,3){
        if(s[i] == '7') flag = true;
    }
    Yes(flag);
}

