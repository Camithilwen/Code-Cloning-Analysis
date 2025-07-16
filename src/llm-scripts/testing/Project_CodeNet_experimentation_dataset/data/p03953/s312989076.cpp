#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

inline void rd(int &X){
    X=0;int w=0;char ch=0;
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while( isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    X=w?-X:X;
}
int n,m,k;
int x[N],d[N],ans[N],t[N];
double a[N];

signed main()
{
    rd(n);
    for(int i=1;i<=n;i++)
        rd(x[i]),d[i]=i,ans[i]=i;
    rd(m);rd(k);
    for(int x,i=1;i<=m;i++)
        rd(x),swap(d[x],d[x+1]);
        while(k)
        {
            if(k&1)
            {
                for(int i=1;i<=n;++i)t[i]=ans[d[i]];
                for(int i=1;i<=n;++i)ans[i]=t[i];
            }
            for(int i=1;i<=n;++i)t[i]=d[d[i]];
            for(int i=1;i<=n;++i)d[i]=t[i];
            k>>=1;
        }
    for(int i=1;i<=n;i++)
        a[i]=x[ans[i]]-x[ans[i]-1];
    for(int i=1;i<=n;i++)
        printf("%.1f\n",a[i]+=a[i-1]);
}
