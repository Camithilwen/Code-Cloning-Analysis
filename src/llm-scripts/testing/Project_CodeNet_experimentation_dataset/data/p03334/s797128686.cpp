#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=100000+100;
const db pi=acos(-1.0);
#define lowbit(x) ((x)&(-x))
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u],v=sq[i].to;i;i=sq[i].nxt,v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

inline ll readll()
{
    ll x=0;int f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int n,d1,d2,col[610][610];

void solve(int d)
{
    int p=0;
    while (d%4==0)
    {
        d/=4;p++;
    }
    if (d&1)
    {
        rep(i,0,n*2-1) rep(j,0,n*2-1)
        {
            int tmp=(i>>p)+(j>>p);
            col[i][j]|=(tmp&1);
        }
    }
    else
    {
        rep(i,0,n*2-1) rep(j,0,n*2-1)
        {
            col[i][j]|=((i>>p)&1);
        }
    }
    
}

int main()
{
    n=read();d1=read();d2=read();
    solve(d1);solve(d2);
    int cnt=0;
    rep(i,0,n*2-1) rep(j,0,n*2-1)
    {
        if (!col[i][j])
        {
            printf("%d %d\n",i,j);cnt++;
            if (cnt==n*n) return 0;
        }
    }
    return 0;
}