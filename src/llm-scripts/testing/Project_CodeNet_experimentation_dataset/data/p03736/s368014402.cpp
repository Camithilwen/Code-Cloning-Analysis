#include<bits/stdc++.h>
using namespace std;
#define il inline
#define gc getchar()
#define ll long long
#define int long long
#define ri register int
#define rc register char
#define rb register bool
#define rp(i,x,y) for(ri i=x;i<=y;++i)
#define my(i,x,y) for(ri i=x;i>=y;--i)
    
const int N=200000+10,inf=1e18;
int n,q,pre,nw,tag[N<<2];
ll tr1[N<<2],tr2[N<<2];
 
il int read()
{
    rc ch=gc;ri x=0;rb y=1;
    while(ch!='-' && (ch>'9' || ch<'0'))ch=gc;
    if(ch=='-')ch=gc,y=0;
    while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
    return y?x:-x;
}
void pushdown(ri nw)
{
	if(!tag[nw])return;
	tag[nw<<1]+=tag[nw];tag[nw<<1|1]+=tag[nw];
	tr1[nw<<1]+=tag[nw];tr1[nw<<1|1]+=tag[nw];
	tr2[nw<<1]+=tag[nw];tr2[nw<<1|1]+=tag[nw];
	tag[nw]=0;
}
void modify(ri nw,ri l,ri r,ri to,ll dat)
{
	if(l==r){tr1[nw]=min(tr1[nw],dat-to),tr2[nw]=min(tr2[nw],dat+to);return;}
	pushdown(nw);ri mid=(l+r)>>1;to<=mid?modify(nw<<1,l,mid,to,dat):modify(nw<<1|1,mid+1,r,to,dat);
	tr1[nw]=min(tr1[nw<<1],tr1[nw<<1|1]);tr2[nw]=min(tr2[nw<<1],tr2[nw<<1|1]);
}
ll query1(ri nw,ri l,ri r,ri to_l,ri to_r)
{
	if(to_l<=l && r<=to_r)return tr1[nw];
	pushdown(nw);ri mid=(l+r)>>1;ll ret=inf;
	if(to_l<=mid)ret=query1(nw<<1,l,mid,to_l,to_r);
	if(mid<to_r)ret=min(ret,query1(nw<<1|1,mid+1,r,to_l,to_r));
	return ret;
}
ll query2(ri nw,ri l,ri r,ri to_l,ri to_r)
{
	if(to_l<=l && r<=to_r)return tr2[nw];
	pushdown(nw);ri mid=(l+r)>>1;ll ret=inf;
	if(to_l<=mid)ret=query2(nw<<1,l,mid,to_l,to_r);
	if(mid<to_r)ret=min(ret,query2(nw<<1|1,mid+1,r,to_l,to_r));
	return ret;
}
ll query(ri nw,ri l,ri r)
{
	if(l==r)return tr1[nw]+l;
	pushdown(nw);ri mid=(l+r)>>1;return min(query(nw<<1,l,mid),query(nw<<1|1,mid+1,r));
}

signed main()
{
//	freopen("2558.in","r",stdin);//freopen("2558.out","w",stdout);
	n=read();q=read();pre=read();memset(tr1,63,sizeof(tr1));memset(tr2,63,sizeof(tr2));modify(1,1,n,read(),0);
	while(q--)
	{
		nw=read();ll dat=min(query1(1,1,n,1,nw)+nw,query2(1,1,n,nw,n)-nw);
		tag[1]+=abs(nw-pre);tr1[1]+=abs(nw-pre);tr2[1]+=abs(nw-pre);modify(1,1,n,pre,dat);pre=nw;
	}
	printf("%lld\n",query(1,1,n));
	return 0;
}