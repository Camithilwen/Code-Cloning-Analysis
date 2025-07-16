#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;


long double dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((double)pow(x2-x1, 2) + (double)pow(y2-y1, 2));
}


int main(){
    ll N; cin >> N;
    vector<ll> X(N), Y(N); for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    long double ans = 0.0;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            ans += dist(X[i], Y[i], X[j], Y[j]) * 2.0;
        }
    }
    cout << setprecision(20) << ans / (long double) N << endl;;
} 
