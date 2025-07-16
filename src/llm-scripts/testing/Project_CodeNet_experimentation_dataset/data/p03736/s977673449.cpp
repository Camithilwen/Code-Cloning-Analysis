#include <cstdio>
typedef long long ll;

template<class T> inline T Abs(const T x){return x>=0?x:-x;}
template<class T> inline T Min(const T a,const T b){return a<b?a:b;}

int n,m,x,y;
ll AT,f[200005],f1[200005],f2[200005],Ans;
const ll Inf=1e18;

void Add1(int x,ll k){for(;x<=n&&k<f1[x];x+=x&-x)f1[x]=k;}
ll Query1(int x,ll k=Inf){for(;x;x^=x&-x)k=Min(k,f1[x]);return k;}
void Add2(int x,ll k){for(;x&&k<f2[x];x^=x&-x)f2[x]=k;}
ll Query2(int x,ll k=Inf){for(;x<=n;x+=x&-x)k=Min(k,f2[x]);return k;}

int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y),Ans=Inf;
    for(int i=1;i<=n;++i)f[i]=f1[i]=f2[i]=Inf;
    for(f[y]=0,Add1(y,-y),Add2(y,y);m--;)
    {
        y=x,scanf("%d",&x);
        ll v=Min(Query1(x)+x,Query2(x)-x)+AT;
        AT+=Abs(x-y);
        if(v-AT<f[y])f[y]=v-AT,Add1(y,f[y]-y),Add2(y,f[y]+y);
    }
    for(int i=1;i<=n;++i)Ans=Min(Ans,f[i]);
    return printf("%lld\n",Ans+AT),0;
}