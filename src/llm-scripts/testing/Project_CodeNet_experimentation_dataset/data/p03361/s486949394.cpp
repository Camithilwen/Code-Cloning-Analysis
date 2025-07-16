#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int h,w;
char s[60][60];
signed main()
{
    h=read(), w=read();
    for(ri int i=1;i<=h;i++) scanf("%s",s[i]+1);
    for(ri int i=1;i<=h;i++)
    for(ri int j=1;j<=w;j++)
    if(s[i][j]=='#')
    {
        if(s[i-1][j]!='#'&&s[i+1][j]!='#'&&s[i][j-1]!='#'&&s[i][j+1]!='#')
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}