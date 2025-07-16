#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;
typedef vector<lint> poly;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

const lint mod = 1e9+7;
const lint INF = mod*mod;
const int MAX = 1<<20;

lint powmod(lint x, lint n){
    lint ret = 1;
    while(n > 0){
        if(n&1) ret *= x, ret %= mod, n -= 1;
        else x *= x, x %= mod, n >>= 1;
    }
    return ret;
}

lint dp[MAX], zero[MAX], cnt[MAX], now;

int main(){
    int n;
    scanf("%d", &n);
    int a[n], s[n+1];
    s[0]=0;
    rep(i, n){
        scanf("%d", &a[i]);
        s[i+1]=s[i]^a[i];
    }
    rep(i, MAX){
        zero[i]=cnt[i]=0;
        dp[i]=1;
    }
    now=0;
    rep(i, n+1){
        if(s[i]==0) ++now;
        else{
            (dp[s[i]]+=zero[s[i]]*(now-cnt[s[i]])%mod)%=mod;
            (zero[s[i]]+=dp[s[i]])%=mod;
            cnt[s[i]]=now;
        }
    }
    if(s[n]!=0){
        printf("%lld\n", dp[s[n]]);
        return 0;
    }
    lint ans=0;
    rep(i, MAX)if(cnt[i]) (ans+=zero[i])%=mod;
    (ans+=powmod(2, now-2))%=mod;
    printf("%lld\n", ans);
}