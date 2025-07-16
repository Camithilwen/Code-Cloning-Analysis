#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

const ll MOD = (ll)1e9 + 7;
const ll MOD2 = 998244353;
const ll HIGHINF = (ll)1e18;
const ll LOWINF = (ll)1e15;
const long double PI = 3.1415926535897932384626433;

template<typename T> vector<T> make_v(size_t N,T init){return vector<T>(N,init);}
template<typename... T> auto make_v(size_t N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}
template <class T> void chmin(T& a, const T b){a=min<T>(a,b);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}

int main() {
    ll N; cin >> N;
    V<ll> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];
    ll sum = 0;
    for(int i = 0; i < N; ++i) sum += a[i];
    auto dp = make_v(N+1,sum + 1,0LL);
    dp[0][0] = 1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= sum; ++j){
            if(j+a[i]<=sum) (dp[i+1][j+a[i]] += dp[i][j]) %=MOD2;
            (dp[i+1][j] += (2LL*dp[i][j]) % MOD2 ) %= MOD2;
        }
    }
    auto dp2 = make_v(N+1,sum+1,0LL);
    dp2[0][0] = 1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= sum; ++j){
            if(j+a[i]<=sum) (dp2[i + 1][j + a[i]] += dp2[i][j]) %= MOD2; 
            (dp2[i+1][j] += dp2[i][j]) %=MOD2;
        }
    }

    ll haf = sum/2 + (sum%2?1:0);
    ll ans = 1;
    for(int i = 0; i < N; ++i) (ans *= 3LL) %= MOD2;
    for(int j = haf; j <= sum; ++j){
        (ans += (MOD2 - (3LL*dp[N][j])%MOD2) ) %= MOD2;
    }
    if(!(sum%2)) (ans += (3LL*dp2[N][sum/2]) % MOD2 ) %= MOD2;
    // for(int i = 0; i < N; ++i) print(i,a[i],dp2[i]);
    // print(N,-N,dp2[N]);

    cout << ans << endl;
    return 0;
}
