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
int sx,sy,tx,ty;
signed main()
{
    sx=read(), sy=read(), tx=read(), ty=read();
    for(ri int i=1;i<=tx-sx;i++) putchar('R');
    for(ri int i=1;i<=ty-sy;i++) putchar('U');
    for(ri int i=1;i<=tx-sx;i++) putchar('L');
    for(ri int i=1;i<=ty-sy;i++) putchar('D');
    putchar('D');
    for(ri int i=1;i<=tx-sx+1;i++) putchar('R');
    for(ri int i=1;i<=ty-sy+1;i++) putchar('U');
    putchar('L');
    putchar('U');
    for(ri int i=1;i<=tx-sx+1;i++) putchar('L');
    for(ri int i=1;i<=ty-sy+1;i++) putchar('D');
    putchar('R');
    puts("");
    return 0;
}