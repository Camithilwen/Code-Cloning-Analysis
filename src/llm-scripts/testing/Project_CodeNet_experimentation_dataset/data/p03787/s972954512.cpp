#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
using namespace std;
LL read(){
    LL nm=0,fh=1; char cw=getchar();
    for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
    for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
    return nm*fh;
}
LL ans,sum0,sum1,sig;
LL n,m,fs[M],nt[M<<1],to[M<<1],col[M],f[M],sz[M],tmp;
LL fd(LL x){return x==f[x]?x:f[x]=fd(f[x]);}
void link(LL x,LL y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
void merge(LL x,LL y){x=fd(x),y=fd(y);if(x!=y) f[x]=y,sz[y]+=sz[x];}
bool check(LL x,LL now){
    if(col[x]) return col[x]==now; col[x]=now;
    for(LL i=fs[x];i!=-1;i=nt[i])
        if(!check(to[i],3-now)) return false;
    return true;
}
int main(){
    n=read(),m=read(),memset(fs,-1,sizeof(fs));
    for(LL i=1;i<=n;i++) f[i]=i,sz[i]=1;
    for(LL i=1;i<=m;i++){
        LL x=read(),y=read();
        link(x,y),link(y,x),merge(x,y);
    }
    for(LL i=1;i<=n;i++) if(fd(i)==i&&sz[i]==1) sig++;
    for(LL i=1;i<=n;i++){
        if(fd(i)!=i||sz[i]==1) continue;
        if(check(i,1)) sum0++;
        else sum1++;
    }
    ans+=sig*((n<<1)-1)-sig*(sig-1);
    ans+=((sum0*sum0)<<1);
    ans+=sum1*(sum0<<1)+sum1*sum1;
    printf("%lld\n",ans);
    return 0;
}