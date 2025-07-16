#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;

int main(){
    int n; cin >> n;
    ll x; cin >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    _rep(i, 1, n){
        if(a[i - 1] > x){
            ans += a[i - 1] - x;
            ans += a[i];
            a[i] = 0;
        }else if(a[i - 1] + a[i] > x){
            ans += (a[i - 1] + a[i] - x);
            a[i] = x - a[i - 1];
        }
    }
    cout << ans << endl;
}