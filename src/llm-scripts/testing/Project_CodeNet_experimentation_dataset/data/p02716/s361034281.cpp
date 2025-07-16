#include <bits/stdc++.h>

#define debug(var)  do{std::cerr << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cerr << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cerr << e << " "; } std::cerr << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n;
v1 a;
v3 dp;
ll bias = 3;

int main(){
    cin >> n;
    a = v1(n);
    for(ll i = 0;i < n;i++){
        cin >> a[i];
    }
    dp = v3(2, v2(6, v1(n+1, -INF)));
    dp[0][3][0] = 0;
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j < 2;j++){
            for(ll k = -2;k <= 1;k++){
                ll x = k + bias;
                if(j == 0){
                    chmax(dp[0][x-1][i+1], dp[j][x][i]);
                    chmax(dp[1][x+1][i+1], dp[j][x][i] + a[i]);
                }else{
                    chmax(dp[0][x-1][i+1], dp[j][x][i]);
                }
            }
        }
    }
    ll d = n/2 - (n-n/2);
    cout << max(dp[0][d+bias][n], dp[1][d+bias][n]) << endl;
}
