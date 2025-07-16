/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
int dp[301][301][301] = {};
string S;

int calc(ll i, ll j, ll k){
    int &res = dp[i][j][k];
    if(~res) return res;
    if(j - i == 0){
        return res = 0;
    }else if(j - i == 1){
        return res = 1;
    }
    res = 0;
    if(S[i] == S[j-1]){
        res = 2 + calc(i+1, j-1, k);
    }else{
        if(k > 0){
            res = 2 + calc(i+1, j-1, k-1);
        }
    }
    res = max(res, calc(i, j-1, k));
    res = max(res, calc(i+1, j, k));
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    ll K;
    cin >> K;
    memset(dp, -1, sizeof(dp));
    ll N = S.size();
    ll ans = calc(0,N,K);
    print(ans);

    

}