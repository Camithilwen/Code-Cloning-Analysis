#include <cstdio>
typedef long long lint;
int const N=1e5+10;
int n,a[N];
int gcd(int x,int y)
{
    if(x==-1 || y==-1) return -x*y;
    if(x==0) return y;
    else return gcd(y%x,x);
}
int g1[N],g2[N];
int main()
{
    scanf("%d",&n);
    lint sum=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    if(n%2==0)
    {
        if(sum%2==1) printf("First");
        else printf("Second");
        return 0;
    }
    if(sum%2==0) {printf("First"); return 0;}
    int cur=0;
    while(true)
    {
        bool flag=false;
        sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        g1[0]=-1; g2[n+1]=-1;
        for(int i=2;i<=n;i++) g1[i]=gcd(g1[i-1],a[i]);
        for(int i=n-1;i>=1;i--) g2[i]=gcd(g2[i+1],a[i]);
        int g;
        for(int i=1;i<=n&&!flag;i++)
        {
            if(a[i]==1) continue;
            g=gcd(gcd(g1[i-1],g2[i+1]),a[i]-1);
            if(((sum-1)/g)%2==1) flag=true;
        }
        if(flag)
            for(int i=1;i<=n;i++) a[i]/=g;
        else
        { 
            if(cur==0) printf("Second");
            else printf("First");
            return 0; 
        } 
        cur^=1;
    }
    return 0;
}