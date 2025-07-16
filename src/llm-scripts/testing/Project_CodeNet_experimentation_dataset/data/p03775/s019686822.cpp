#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

vector<ll> enum_divisors(ll N){
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i){
        if (N % i == 0){
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int digit(ll a){
    int res = 0;
    while(a > 0){
        a /= 10;
        res++;
    }
    return res;
}

int f(ll a, ll b){
    return max(digit(a),digit(b));
}


int main(){
    ll N; cin >> N;

    vector<ll> divisors = enum_divisors(N);

    int ans = 100000000;
    for(auto divisor : divisors){
        ll a = divisor;
        ll b = N/divisor;
        ans = min(ans, f(a,b));
    }

    cout << ans << endl;

}