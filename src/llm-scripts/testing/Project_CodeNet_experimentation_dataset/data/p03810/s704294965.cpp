#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int N;
int A[100000];

int res(){
    int K = 0;
    rep(i, N){
        if(A[i]%2 == 0) K++;
    }
    if(K&1) return 1;
    if(K != N-1) return 0;
    int g = A[0]&~1;
    rep(i, N){
        if(A[i] == 1) return 0;
        if(A[i]%2 == 1) A[i]--;
        g = gcd(g, A[i]);
    }
    rep(i, N) A[i] /= g;
    return res()^1;
}

int main(){
    cin >> N;
    rep(i, N) cin >> A[i];
    cout << (res()? "First" : "Second") << endl;
}