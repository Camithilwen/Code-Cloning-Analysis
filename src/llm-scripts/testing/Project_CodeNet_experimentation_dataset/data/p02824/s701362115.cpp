#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ld long double
#define ff first
#define ss second
const ll mod =   1e9 +7  ;
ll multiply(ll a, ll b ){ return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
void solve(){
    ll n , m , v ,  p ;
    cin >> n >> m >> v >> p ;
    vector < ll > a(n) ;
    for( int i = 0 ; i < n ; i++) cin >> a[i]  ;
    sort(a.begin(),a.end());
    vector < ll > pre(n) ;
    pre[0] = a[0] ;
    for( int i = 1 ; i < n ; i++) pre[i] = pre[i-1] + a[i] ;
//    for( int i = 0 ; i < n ; i++) cout << a[i] << " "  ;
//    cerr << "\n" ;
    int ans = 0 ;
    for( int i = n-1 ; i >= 0  ; i--){
        ll r = n-p ;
        if(i>=r){
            ans++;
            continue ;
        }
        if(a[i]+m>=a[r]){
            int vote = v-p-i ;
            if(vote>0){
                ll sum = pre[r]-pre[i] ;
               // cout << i << " " << vote << " " << sum << " " << (a[i]+m)*(r-i)-sum<< "\n";
                if(m*vote<=(a[i]+m)*(r-i)-sum){
                    ans++;
                }
            }
            else{
                ans++;
            }
        }
        else{
            break ;
        }
    }
    cout << ans ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1 ;
    //cin >> t ;
    while(t--){
        solve( );
    }
}
