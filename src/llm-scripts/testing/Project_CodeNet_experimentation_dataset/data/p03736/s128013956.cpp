#include<bits/stdc++.h>
#define maxn 200005
#define LL long long
using namespace std;
const int mod = 1e9+7;
int n,Q,pre,now;
struct Seg{
	LL mn[maxn<<2],tag[maxn<<2]; int flg;
	Seg(){memset(mn,0x3f,sizeof mn);}
	inline void add(int i,LL v){mn[i]+=v,tag[i]+=v;}
	inline void down(int i){if(tag[i]) add(i<<1,tag[i]),add(i<<1|1,tag[i]),tag[i]=0;}
	void ins(int i,int l,int r,int x,LL v){
		if(l==r) {mn[i]=min(mn[i],v+l*flg);return;}
		int mid=(l+r)>>1; down(i);
		x<=mid?ins(i<<1,l,mid,x,v):ins(i<<1|1,mid+1,r,x,v);
		mn[i]=min(mn[i<<1],mn[i<<1|1]);
	}
	LL qry(int i,int l,int r,int x,int y){
		if(x<=l&&r<=y) return mn[i];
		int mid=(l+r)>>1; LL ret=mn[0]; down(i);
		if(x<=mid) ret=min(ret,qry(i<<1,l,mid,x,y));
		if(y>mid) ret=min(ret,qry(i<<1|1,mid+1,r,x,y));
		return ret;
	}
	LL whole(int i,int l,int r){
		if(l==r) return mn[i]+l;
		int mid=(l+r)>>1; down(i);
		return min(whole(i<<1,l,mid),whole(i<<1|1,mid+1,r));
	}
}T1,T2;
int main()
{
	scanf("%d%d%d%d",&n,&Q,&pre,&now),T1.flg=-1,T2.flg=1;
	T1.ins(1,1,n,now,0),T2.ins(1,1,n,now,0);
	for(int i=1;i<=Q;i++,pre=now){
		scanf("%d",&now); if(now==pre) continue;
		LL tmp=min(T1.qry(1,1,n,1,now)+now,T2.qry(1,1,n,now,n)-now);
		T1.add(1,abs(now-pre)),T2.add(1,abs(now-pre));
		T1.ins(1,1,n,pre,tmp),T2.ins(1,1,n,pre,tmp);
	}
	printf("%lld\n",T1.whole(1,1,n));
}