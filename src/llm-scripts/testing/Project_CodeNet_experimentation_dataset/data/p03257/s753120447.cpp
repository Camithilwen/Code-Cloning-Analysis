/*
t.me/ivanesipovvpered
*/
#pragma ARCENIY_KIRILLOV_POVELITEL_KROKODILOV
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC push_options
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC pop_options
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(), a.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
typedef long long ll;

const double EPS = 1e-5;
const int mod = 1e9 + 7;
const ll INFLL = 1e18;
const int INF = 1e9;
const int maxn = 1e6 + 3;

ll gcd(ll a, ll b){
    if (b == 0ll)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b) )* b;
}

bool is_prime(ll a){
    if (a == 2 || a == 3 || a == 5 || a == 7) return true;
    if (a % 2 == 0 || a%3 == 0 || a%5 == 0 || a%7 == 0)
        return false;
    for (ll i = 11; i * i <= a; i += 2){
        if (a % i == 0)
            return false;
    }
    return true;
}

ll binpow(ll a, int n){
    if (a == 0)
        return 1;
    if (a % 2 == 0){
        ll q = binpow(a, n / 2);
        return (q * q)  ;
    }else return (a * binpow(a, n - 1) ) ;
}





















main(){
    int n;
    cin >> n;
    vector<ll> primes;
    ll a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }
    int fe = 2;
    while (primes.size() < n + n + 2){
        if (is_prime(fe)) primes.pb(fe);
        fe++;
    }
    int q = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ((i + j) % 2 == 0){
                a[i][j] = primes[(i + j) / 2];
                q = max(q, (i + j) / 2);
            }
        }
    }
    for (int j = n - 1; j > -1; j--){
        for (int i = 0; i < n; i++){
            if ((i + j) % 2 == 0){
                a[i][j] *= primes[q + 1 + (i + (n - j)) / 2];
            }
        }
    }
    map<ll,bool> kek;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j]) continue;
            int qe = 1, we = 1;
            if (i)
                qe = a[i-1][j];
            if (i < n - 1)
                qe = lcm(qe, a[i+1][j]);
            if (j)
                we = a[i][j-1];
            if (j < n-1)
                we = lcm(we,a[i][j+1]);
            int ce = lcm(qe, we);
            int flex = ce;
            while (kek[ce]){
                ce += flex;
            }
            kek[ce] = 1;
            a[i][j] = ce + 1;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j< n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
