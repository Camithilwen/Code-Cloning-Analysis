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
int n,Y;
signed main()
{
    n=read(), Y=read();
    for(ri int i=0;i<=Y/10000;i++)
    for(ri int j=0;j<=Y/5000&&i+j<=n;j++)
    if(i*10000+j*5000+(n-i-j)*1000==Y)
    {
        printf("%lld %lld %lld\n",i,j,n-i-j);
        return 0;
    }
    puts("-1 -1 -1");
    return 0;
}