#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans[N],a[N],b[N],t[N<<2],t1[N<<2],t2[N<<2];
void update(int l,int r,int k)
{
    t1[k]=t[k]+r-l;t2[k]=t[k];
    if(l!=r)
    {
        int m=l+r>>1;
        t[k<<1]=t[k];t[k<<1|1]=t[k]+m+1-l;
    }
    t[k]=0;
}
int query(int l,int r,int k,int x)
{
    if(t[k]) update(l,r,k);
    if(l>x) return m+1;
    if(r<=x) return t1[k];
    int m=l+r>>1;
    int a=query(l,m,k<<1,x),b=query(m+1,r,k<<1|1,x);
    if(x<=r) a+=x>=m?x-m:0;
    else a+=r-m;
    t2[k]=min(t2[k<<1],t2[k<<1|1]);
    t1[k]=min(t1[k<<1]+r-m,t1[k<<1|1]);
    return min(a,b);
}
void update(int l,int r,int k,int x,int y,int d)
{
    if(t[k]) update(l,r,k);
    if(r<x||l>y) return;
    if(l>=x&&r<=y)
    {
        t[k]=d+l-x;
        update(l,r,k);
        return;
    }
    int m=l+r>>1;
    update(l,m,k<<1,x,y,d);update(m+1,r,k<<1|1,x,y,d);
    t2[k]=min(t2[k<<1],t2[k<<1|1]);
    t1[k]=min(t1[k<<1]+r-m,t1[k<<1|1]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++)
    {
        int d=min(m+1,query(1,m,1,a[i]-1)+1);
        update(1,m,1,a[i],b[i],d);
        ans[i]=t2[1];
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]>=m) ans[i]=-1;
        else ans[i]+=i;
        printf("%d\n",ans[i]);
    }
}
