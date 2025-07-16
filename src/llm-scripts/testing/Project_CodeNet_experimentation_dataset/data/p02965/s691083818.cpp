#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
const int mod=998244353;
LL jc[2500005];
void add(LL &x,LL y){x=(x+y)%mod;}
LL sqrr(LL x){return x*x%mod;}
LL ksm(LL x,int y){
    if (y==0) return 1;if (y==1) return x;
    LL ans=sqrr(ksm(x,y>>1));
    if (y&1) ans=ans*x%mod;
    return ans;
}
LL ny(LL x){return ksm(x,mod-2);}
LL C(int n,int m){return jc[n]*ny(jc[m])%mod*ny(jc[n-m])%mod;}
LL calf(int n,int s){
    return C(n+s-1,s);
}
LL cal1(int n,int m,int k){
    if (k>n) return 0;
    if ((k^m)&1) return 0;
    return C(n,k)*calf(n,(m*3-k)/2)%mod;
}
LL cal2(int n,int m,int k){
    if (k>n) return 0;
    return C(n,k)*k%mod*calf(k,m-k)%mod;
}
void init(){
    const int n=2500000;
    jc[0]=1;
    for (int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
}
int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    init();
    int n,m,m3;cin>>n>>m;m3=m*3;
    LL ans=calf(n,m3);
    for (int i=m+1;i<=m3;i++) add(ans,mod-cal1(n,m,i));
    for (int i=1;i<=m;i++) add(ans,mod-cal2(n,m,i));
    cout<<ans<<endl;
    return 0;
}
