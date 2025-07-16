//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
ll pow(ll x, ll ntimes) {
    ll ret = 1;
    while (ntimes > 0) {
        if ((ntimes & 1) == 1) {
            ret = ret * x;
        }
        x = x * x;
        ntimes >>= 1;
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll ans = 1;
    vector<bool> prime(n+1,true);
    for(ll i=2;i<=n;++i){
        if(prime[i]==true){
            ll cnt = 0;
            for(ll j=2*i;j<=n;j+=i){
                prime[j]=false;
            }
            ll t = 1;
            while(pow(i,t)<=n){
                ll x = pow(i,t);
                cnt += (n/x);
                t++;
            }
            ans *= (cnt+1);
            ans %= mod;
        }
    }
    cout << ans << endl;

    return 0;
}