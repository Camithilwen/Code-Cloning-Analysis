#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    ll N = 50;
    ll a[55] = {};
    rep(i,0,N) a[i] = i;
    ll v = K / N;
    rep(i,0,N) a[i] += v;
    ll amari = K % N;
    rep(i,0,amari){
        rep(j,0,N){
            if(i == j){
                a[j] += N;
            }else{
                a[j]--;
            }
        }
    }
    print(N);
    printa(a,N);

}
