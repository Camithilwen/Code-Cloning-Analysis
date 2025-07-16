#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,s,x[100009],p[100009],ans[100009];

void call(int l,int r)
{
    if(l==r)
    {
        ans[l]=fabs(x[l]);
        return;
    }
    if(x[l]>0)
    {
        call(l,r-1);
        ans[r]=ans[r-1]+x[r]-x[r-1];
        return;
    }
    if(x[r]<0)
    {
        call(l+1,r);
        ans[l]=ans[l+1]+x[l+1]-x[l];
        return;
    }
    if(p[l]>=p[r])
    {
        p[l]+=p[r];
        call(l,r-1);
        ans[r]=ans[l]+x[r]-x[l];
        return;
    }
    p[r]+=p[l];
    call(l+1,r);
    ans[l]=ans[r]+x[r]-x[l];
    return;
}

int main()
{
    scanf("%lld %lld",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld",&x[i],&p[i]);
        x[i]-=s;
    }
    call(1,n);
    LL foo=max(ans[1],ans[n]);
    cout<<foo<<endl;
    return 0;
}
