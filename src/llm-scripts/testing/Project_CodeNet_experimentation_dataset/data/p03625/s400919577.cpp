#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair <int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n; ++i){
        cin >> ara[i];
    }
    sort(ara, ara + n);
    ll a(0), b(0);
    ll len = n - 1;
    char c(1);
    while(len){
        if(ara[len] == ara[len - 1]){
            if(c){
                a = ara[len];
                c = 0;
            }
            else{
                b = ara[len];
                break;
            }
            len--;
        }
        len--;
    }
    cout << a * b << nl;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
