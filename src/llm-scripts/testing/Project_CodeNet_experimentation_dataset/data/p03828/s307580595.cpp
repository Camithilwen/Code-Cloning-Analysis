#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=210, Mod=1e9+7;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,res;
map<int,int> Q;
signed main()
{
    n=read();
    for(ri int i=2;i<=n;i++)
    {
        int x=i;
        for(ri int j=2;j*j<=x;j++)
        {
            if(x%j) continue;
            while(x%j==0) Q[j]++, x/=j;
        }
        if(x>1) Q[x]++;
    }
    res=1;
    for(ri map<int,int>::iterator s=Q.begin();s!=Q.end();s++)
        res=res*(s->second+1)%Mod;
    printf("%lld\n",res);
    return 0;
}