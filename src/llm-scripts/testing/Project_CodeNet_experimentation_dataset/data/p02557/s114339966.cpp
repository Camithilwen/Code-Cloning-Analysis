// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_dedges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B);}
#define in_wedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C), v[B].pb(A, C);}
#define in_dwedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C);}
#define endl "\n"

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 18;
const int inf = 2e9;

const int N = 2e5 + 5;
int a[N], b[N];
int A[N], B[N];
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    quickio
    int n;
    cin >> n;
    repp(i, 1, n) cin >> a[i];
    repp(i, 1, n) cin >> b[i];

    repp(i, 1, n) A[a[i]]++, B[b[i]]++;
    repp(i, 1, n) if(A[i] + B[i] > n){
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    rep(i, 1, N) A[i] += A[i - 1], B[i] += B[i - 1];
    int mx = 0;
    repp(i, 1, N) mx = max(mx, A[i] - B[i - 1]);
    repp(i, 1, n) cout << b[(i - mx + n - 1) % n + 1] << " ";
}

ll power(ll x, ll y){ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}