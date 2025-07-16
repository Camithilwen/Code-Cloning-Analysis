#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int s[10];
inline bool Check(int x)
{
    int cnt=0;
    while(x) s[++cnt]=x%10, x/=10;
    if(s[1]==s[5]&&s[2]==s[4]) return 1;
    return 0;
}
signed main()
{
    int a,b;
    a=read();
    b=read();
    int res=0;
    for(ri int i=a;i<=b;i++) if(Check(i)) res++;
    printf("%lld\n",res);
    return 0;
}