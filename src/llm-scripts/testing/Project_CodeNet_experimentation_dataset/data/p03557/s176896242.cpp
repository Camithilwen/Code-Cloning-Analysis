#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],b[N],c[N];
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    for(ri int i=1;i<=n;i++) b[i]=read();
    for(ri int i=1;i<=n;i++) c[i]=read();
    sort(a+1,a+1+n), sort(b+1,b+1+n), sort(c+1,c+1+n);
    int res=0;
    for(ri int i=1;i<=n;i++)
    {
        int p=lower_bound(a+1,a+1+n,b[i])-a;
        int q=upper_bound(c+1,c+1+n,b[i])-c;
        res+=(n-q+1)*(p-1);
    }
    printf("%lld\n",res);
    return 0;
}