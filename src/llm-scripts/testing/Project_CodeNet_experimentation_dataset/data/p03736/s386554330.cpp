#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define gc getchar()
#define ll long long
#define int long long
#define ri register int
#define rc register char
#define rb register bool
#define rp(i,x,y) for(ri i=x;i<=y;++i)
#define my(i,x,y) for(ri i=x;i>=y;--i)
using namespace std;
    
il int read()
{
    rc ch=gc;ri x=0;rb y=1;
    while(ch!='-' && (ch>'9' || ch<'0'))ch=gc;
    if(ch=='-')ch=gc,y=0;
    while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
    return y?x:-x;
}
ll min1[1000001], min2[1000001], adds[1000001];
inline void down(int nw) 
{
    if (!adds[nw])return;
    adds[ls(nw)] += adds[nw];
    adds[rs(nw)] += adds[nw];
    min1[ls(nw)] += adds[nw];
    min2[ls(nw)] += adds[nw];
    min1[rs(nw)] += adds[nw];
    min2[rs(nw)] += adds[nw];
    adds[nw] = 0;
}
inline void up(int nw) 
{
    min1[nw] = min(min1[ls(nw)], min1[rs(nw)]);
    min2[nw] = min(min2[ls(nw)], min2[rs(nw)]);
}
void setpt(int l, int r, int nw, int pt, ll num) 
{
    if (l == r) 
	{
        min1[nw] = min(min1[nw], num - l);
        min2[nw] = min(min2[nw], num + l);
        return;
    }
    int mid = (l + r) >> 1;down(nw);
    if (pt <= mid)setpt(l, mid, ls(nw), pt, num);
    else setpt(mid + 1, r, rs(nw), pt, num);
    up(nw);
}
ll query1(int rl, int rr, int l, int r, int nw) 
{
    if (rl == l && rr == r)return (min1[nw]);
    int mid = (l + r) >> 1;down(nw);
    if (rl > mid)return (query1(rl, rr, mid + 1, r, rs(nw)));
    if (rr <= mid)return (query1(rl, rr, l, mid, ls(nw)));
    return (min(query1(rl, mid, l, mid, ls(nw)), query1(mid + 1, rr, mid + 1, r, rs(nw))));
}
ll query2(int rl, int rr, int l, int r, int nw) 
{
    if (rl == l && rr == r)return (min2[nw]);
    int mid = (l + r) >> 1;down(nw);
    if (rl > mid)return (query2(rl, rr, mid + 1, r, rs(nw)));
    if (rr <= mid)return (query2(rl, rr, l, mid, ls(nw)));
    return (min(query2(rl, mid, l, mid, ls(nw)), query2(mid + 1, rr, mid + 1, r, rs(nw))));
}
ll query(int l, int r, int nw) 
{
    if (l == r)return (min1[nw] + l);
    int mid = (l + r) >> 1;down(nw);return (min(query(l, mid, ls(nw)), query(mid + 1, r, rs(nw))));
}
signed main() 
{
//	freopen("2558.in","r",stdin);
    int n = read(), q = read(), pre = read();
    memset(min1, 0x3f, sizeof(min1));memset(min2, 0x3f, sizeof(min2));setpt(1, n, 1, read(), 0);
    for (register int i = 1; i <= q; i++) 
	{
        int nw = read();
        ll cjr = min(query1(1, nw, 1, n, 1) + nw, query2(nw, n, 1, n, 1) - nw);
        adds[1] += abs(nw - pre);
        min1[1] += abs(nw - pre);
        min2[1] += abs(nw - pre);
        setpt(1, n, 1, pre, cjr);
        pre=nw;
    }
    printf("%lld\n",query(1,n,1));
    return (0);
}