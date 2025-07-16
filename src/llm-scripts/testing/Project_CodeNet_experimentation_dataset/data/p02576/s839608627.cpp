#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = (ll)1e18;
const int N = 2e5 + 5;
const ll MOD = 1e9+7;
 
int parent[N];
 
int gcd(int a, int b) { 
    if (a == 0) 
        return b;  
    return gcd(b%a, a);  
} 
   
int lcm(int a, int b) {  
    return (a*b)/gcd(a,b);  
} 
 
ll pow(ll x, ll y, ll p) {
    if(y == 0) return 1;
    ll res = 1;
    x %= p;
    if(x == 0) return 0LL;
    while(y > 0) {
        if(y & 1) res = (res*x) % p;
        y >>= 1;
        x = (x*x) % p;
    }
    return res;
}
 
int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
 
void Union(int x, int y) {
    int xPar = find(x), yPar = find(y);
    if(xPar != yPar) parent[xPar] = yPar;
}
 
ll nCr(ll n, ll r) {
    ll res = 1;
    for(ll i=1;i<=r;i++) {
        res = res * (n - r + i) / i;
        // is different from
        // res *= (n -r + i) / i;
    }
    return res;
}
 
int ask(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int v;
    cin >> v;
    return v;
}

void solve() {
    int n, x, t;
    cin >> n >> x >> t;
    cout << (int)(ceil)(n / (double)x) * t << endl;
    return;
} 
 
int main()
{
    IOS
    //int t;
    //cin >> t;
    //while(t--) 
    solve();
    return 0; 
}