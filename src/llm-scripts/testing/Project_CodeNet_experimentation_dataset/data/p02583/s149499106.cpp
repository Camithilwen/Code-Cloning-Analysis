#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#include <cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
typedef std::pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

int main()
{
    int a[105],n;
    n=read();
    REP(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<=n;k++)
                if(a[i]+a[j]>a[k] && a[i]!=a[j] && a[j]!=a[k])
                    ans++;
    cout<<ans;
    
    return 0;
}
