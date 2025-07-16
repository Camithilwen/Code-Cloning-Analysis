#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
int fa[maxn],co[maxn];
bool bz[maxn],pd[maxn];
int i,j,k,l,r,t,n,m,cnt;
ll ans;
int getfa(int x){
    if (!fa[x]) return x;
    int t=getfa(fa[x]);
    co[x]^=co[fa[x]];
    return fa[x]=t;
}
int main(){
    scanf("%d%d",&n,&m);
    fo(i,1,m){
        scanf("%d%d",&j,&k);
        bz[j]=1;bz[k]=1;
        l=getfa(j);r=getfa(k);
        if (l<r){
            swap(l,r);
            swap(j,k);
        }
        if (l==r&&co[j]==co[k]) pd[l]=1;
        if (l==r) continue;
        pd[r]|=pd[l];
        fa[l]=r;
        co[l]=co[j]^co[k]^1;
    }
    fo(i,1,n)
        if (!bz[i]) cnt++;
    ans=(ll)cnt*(n-cnt)*2+(ll)cnt*cnt;
    cnt=0;
    fo(i,1,n)
        if (bz[i]&&!fa[i]) cnt++;
    ans+=(ll)cnt*cnt;
    cnt=0;
    fo(i,1,n)
        if (bz[i]&&!fa[i]&&!pd[i]) cnt++;
    fo(i,1,n)
        if (bz[i]&&!fa[i]&&!pd[i]) ans+=(ll)cnt;
    printf("%lld\n",ans);
}