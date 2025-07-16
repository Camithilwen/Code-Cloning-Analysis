#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=998244353;
const LL LINF=1LL<<60;
const int INF=1<<30;


vector<LL> fact;
vector<LL> inver(3000001);
 
LL combi(int n,int r){
    if(n<r||n<0||r<0) return 0;
    return fact[n]%mod*inver[n-r]%mod*inver[r]%mod;
}
 
 
LL fpow(LL a, LL n){
    LL x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%mod;
        }
        a=a*a%mod;
        n >>= 1;
    }
    return x;
}
 
void set_combi(){
    LL s=1;
    fact.push_back(1);
    for(int i=1;i<=3000000;i++){
        s*=i;
        s%=mod;
        fact.push_back(s);
    }
    inver[3000000]=fpow(fact[3000000],mod-2);
    for(int i=2999999;i>=0;i--){
        inver[i]=inver[i+1]*(i+1)%mod;
    }
}
 
LL hcombi(int n,int r){
    return combi(n+r-1,r); 
}



int main(){
    set_combi();
    LL n,m;cin >> n >> m;
    LL ans = 0;
    for (int i = m; i >= 0; i-=2) {
        ans = (ans + hcombi(n,m+(m-i)/2) * combi(n,i))%mod;
    }
    for (int i = 2*m+1; i <= 3*m; i++) {
        ans = (ans - (n * hcombi(n-1,3*m-i))%mod + mod)%mod;
    }
    cout << ans << endl;
    return 0;
}
