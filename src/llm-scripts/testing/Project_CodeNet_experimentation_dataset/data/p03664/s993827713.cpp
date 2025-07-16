#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=17;
const int INF=0x3f3f3f3f;
ll n,m,conn[MAX][MAX],dist[MAX][MAX],dp[MAX][1<<MAX],visit[MAX][1<<MAX],calc[1<<MAX],trk[MAX],ans;
void calc_build(ll x,ll v,ll idx){
    //printf("%lld %lld %lld\n",x,v,idx);
    if(idx>=n) {
        calc[x]=v;
        return;
    }
    calc_build(x,v,idx+1);
    trk[idx]=1;
    for(ll i=0;i<idx;i++) if(trk[i]) v+=dist[i][idx];
    calc_build(x+(1<<idx),v,idx+1);
    trk[idx]=0;
}
ll dp_build(ll x,ll bit){
    if(x==n-1) return dp[x][bit]=calc[bit];
    if(visit[x][bit]==0){
        visit[x][bit]=1;
        dp[x][bit]=-INF;
        for(ll i=0;i<n;i++) if(((1<<i)&bit)&&conn[i][x]){
            ll cmp[MAX],cmp_cnt=0;
            for(ll j=0;j<n-1;j++) if(((1<<j)&bit)&&i!=j&&x!=j) cmp[cmp_cnt++]=j;
            for(ll j=0;j<(1<<(cmp_cnt));j++){
                ll g1=1<<x,g2;
                for(ll k=0;k<cmp_cnt;k++) if((1<<k)&j) g1+=(1<<cmp[k]);
                g2=bit-g1;
                dp[x][bit]=max(dp[x][bit],calc[g1]+dp_build(i,g2)+dist[x][i]);
            }
        }
    }
    return dp[x][bit];
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<m;i++){
        ll t1,t2,t;
        scanf("%lld%lld%lld",&t1,&t2,&t);
        t1--,t2--;
        conn[t1][t2]=1,dist[t1][t2]=t;
        conn[t2][t1]=1,dist[t2][t1]=t;
        ans+=t;
    }
    calc_build(0,0,0);
    printf("%lld\n",ans-dp_build(0,(1<<n)-1));
}
