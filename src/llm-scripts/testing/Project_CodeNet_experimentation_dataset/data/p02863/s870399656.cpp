#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
	#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,T;
    cin >> N >> T;
    vector<ll> A(N), B(N), C(N+1);
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    vector<vector<ll>> dp(N+1, vector<ll>(T+1)), dp2(N+1, vector<ll>(T+1));
    rep(i,N){
        rep(j,T){
            if(j+A[i] <= T){
                dp[i+1][j+A[i]]=max(dp[i+1][j+A[i]], dp[i][j]+B[i]);
            }
            dp[i+1][j+1]=max(dp[i+1][j+1], dp[i+1][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j+1]);
        }
    }
    for(ll i=N;i>0;i--){
        rep(j,T){
            if(j+A[i-1] <= T){
            	dp2[i-1][j+A[i-1]]=max(dp2[i-1][j+A[i-1]], dp2[i][j]+B[i-1]);
            }
            dp2[i-1][j+1]=max({dp2[i-1][j+1], dp2[i][j+1], dp2[i-1][j]});
        }
    }
    ll ans = 0;
    REP(i,0,N){
        rep(j,T){
            cmax(ans, dp[i][j] + B[i] + dp2[i+1][T-1-j]);
        }
    }
    cout << ans << endl;
}