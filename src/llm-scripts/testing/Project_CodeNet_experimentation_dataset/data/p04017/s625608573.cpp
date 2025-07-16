#include <bits/stdc++.h>
using namespace std;
const int maxn=112345;
int n,x[maxn],l,q,f[maxn][20];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&x[i]);
    scanf("%d%d",&l,&q);
    for (int i=1;i<n;++i) {
        int t=upper_bound(x+1,x+1+n,x[i]+l)-x-1;
        f[i][0]=t;
    }
    f[n][0]=f[n+1][0]=n+1;
    for (int i=1;i<20;++i)
        for (int j=1;j<=n+1;++j)
            f[j][i]=f[f[j][i-1]][i-1];
    while (q--) {
        int a,b;scanf("%d%d",&a,&b);
        if (a>b) swap(a,b);
        int num=0;
        for (int i=19;i>=0;--i)
            if (f[a][i]<=b) {
                num+=1<<i;
                a=f[a][i];
            }
        printf("%d\n",num+(a!=b));
    }
    return 0;
}
