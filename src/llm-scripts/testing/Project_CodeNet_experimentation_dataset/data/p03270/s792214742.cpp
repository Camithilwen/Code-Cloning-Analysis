#include <bits/stdc++.h>
using namespace std;
const int MAXN=2020,MOD=998244353;

template <class T>
inline bool read(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0;
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

template <class T>
inline void write(T x)
{
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

int C[MAXN<<1][MAXN<<1],pw[MAXN<<1],n,k;

inline int add(int x,int y)
{
    return (1LL*x+y)%MOD;
}

inline int mul(int x,int y)
{
    return 1LL*x*y%MOD;
}

inline void init(int n)
{
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=1,C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=add(C[i-1][j-1],C[i-1][j]);
    }
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=mul(pw[i-1],2);
}

inline int f(int x,int y,int z)
{
    if(y<0) return 0;
    int ret=0;
    for(int q=0;q<=z&&q<=x;++q)
    {
        if (q+y-1<=z+y-1&&q+y-1>=0)
        {
            ret=add(ret,mul(C[x][q],mul(pw[q],C[z+y-1][q+y-1])));
        }
    }
    return ret;
}

int cnt,ans;

int main()
{
    read(k),read(n);
    init(n+k);
    for(int i=2;i<=2*k;i++)
    {
        cnt=0;
        for (int j=1;j<=k;++j)
        {
            if (1<=i-j&&i-j<=k) ++cnt;
        }
        if(i&1)
            ans=f(cnt/2,k-cnt,n);
        else
        {
            ans=f((cnt-1)/2,k-cnt,n);
            ans=add(ans,f((cnt-1)/2,k-cnt,n-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}