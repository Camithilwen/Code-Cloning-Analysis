#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int cnt[N],ans[N],a[N];
int n,q,bl;
int res;
struct node
{
    int l,r,p;

}e[N];
bool cmp(const node &a,const node &b)
{
    return (a.l/bl)==(b.l/bl) ? a.r<b.r :a.l>b.l;
}
void remove(int x)
{
    if((--cnt[a[x]])==0) res--;
}
void add(int x)
{
    if((++cnt[a[x]])==1) res++;
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
     bl=sqrt(n);
    for(int i=1,l,r;i<=q;i++)
    {
        scanf("%d %d",&l,&r);
        e[i]={l,r,i};
    }
  //  cout<<"--------------"<<endl;

    sort(e+1,e+1+q,cmp);
   // cout<<"*****"<<endl;
    res=0;
    int curL=1,curR=0;
    for(int i=1;i<=q;i++)
    {
        //cout<<i<<endl;
        int L=e[i].l,R=e[i].r;
        while(curL<L) remove(curL++);
        while(curL>L) add(--curL);
        while(curR<R) add(++curR);
        while(curR>R) remove(curR--);
        ans[e[i].p]=res;
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);

}
