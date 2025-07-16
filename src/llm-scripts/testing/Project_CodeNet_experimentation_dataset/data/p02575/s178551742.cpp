#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstring>
#include<bitset>
#include<stack>
#include<time.h>



#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define ALL(x) x.begin(),x.end()
#define sz(a) ((int)a.size())
#define getmid ((l+r)>>1)
#define mst(var,val) memset(var,val,sizeof(var))
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define lowbit(x) x&(-x)
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
#ifdef local
#define dbg(args...) cout << #args << " -> ", err(args);
void err(){ cout << endl; }
template<typename T, typename... Args>
void err(T a, Args... args){ cout << a << ' '; err(args...); }
#else
#define dbg(args...)
#endif // local

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <double, double> pdd;
const int inf=0x3f3f3f3f;
const long long INF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const long double eps=1e-8;
const int mod=1e9+7;
const int maxn=3e5+100;
const int N=1e6+1000;
const int M=500+10;
const ll mm=(1LL<<32);

template <class T>
inline void read(T &x)
{
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar())
        f ^= c == '-';
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10)
        ++len;
    for (; len; --len, x %= y, y /= 10)
        putchar(x / y + 48);
}
ll qpow(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

struct node{
    ll lazy[N<<2],mi[N<<2];
    void pushdown(int rt)
    {
        if(lazy[rt])
        {
            mi[ls]+=lazy[rt];mi[rs]+=lazy[rt];
            lazy[ls]+=lazy[rt];lazy[rs]+=lazy[rt];
            lazy[rt]=0;
        }
    }
    void pushup(int rt)
    {
        mi[rt]=min(mi[ls],mi[rs]);
    }
    void update(int rt,int l,int r,int L,int R,ll val)
    {
        if(L<=l&&r<=R)
        {
            lazy[rt]+=val;
            mi[rt]+=val;
            return ;
        }
        pushdown(rt);
        int mid=getmid;
        if(L<=mid) update(ls,l,mid,L,R,val);
        if(R>mid) update(rs,mid+1,r,L,R,val);
        pushup(rt);
    }
    ll query(int rt,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R) return mi[rt];
        pushdown(rt);
        int mid=getmid;
        ll res=INF;
        if(L<=mid) res=min(res,query(ls,l,mid,L,R));
        if(R>mid) res=min(res,query(rs,mid+1,r,L,R));
        return res;
    }
}x,y;
int A[N],B[N];
int main()
{
#ifdef local
    freopen("in.txt","r",stdin);
#endif // local
    IOS;cout.tie(0);
    int H,W;cin>>H>>W;
    rep1(i,W) y.update(1,1,W,i,i,-i);
    rep1(i,H) cin>>A[i]>>B[i];
    for(int i=1;i<=H;++i)
    {
        int r=B[i]+1;
        if(r<=W)
        {
            ll mi=y.query(1,1,W,1,B[i]);
            ll now=x.query(1,1,W,r,r);
            if(now>mi+r)
            {
                x.update(1,1,W,r,r,mi+r-now);
                y.update(1,1,W,r,r,mi-y.query(1,1,W,r,r));
            }
        }
        x.update(1,1,W,A[i],B[i],inf);
        y.update(1,1,W,A[i],B[i],inf);
        //x.update(1,1,W,1,W,1);
        //y.update(1,1,W,1,W,1);
        ll ans=x.query(1,1,W,1,W);
        if(ans>=inf) cout<<-1<<"\n";
        else cout<<ans+i<<"\n";
    }
    return 0;
}
