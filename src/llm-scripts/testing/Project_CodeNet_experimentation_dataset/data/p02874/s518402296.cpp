#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}

struct wzy{
	int l,r;
}co[200010];
inline bool cmp(wzy a,wzy b){
	return a.l<b.l;
}
inline int d(int ll,int rr){
	return max(0,rr-ll+1);
}

int main(){
	int n;read(n);int ans=0;
	int pos1=0;int pos2=0;int mx_l=0;int n1=0;int n2=0;int mi_r=INT_MAX;
	rep(i,1,n){
		read(co[i].l);read(co[i].r);
		if(co[i].l>mx_l){mx_l=co[i].l;pos1=i;}
		if(co[i].r<mi_r){mi_r=co[i].r;pos2=i;}	
	}
	n1=co[pos1].r;n2=co[pos2].l;int len=0;
	rep(i,1,n){
		int q1=co[i].l;int q2=co[i].r;
		if(i!=pos1&&i!=pos2){co[++len].l=q1;co[len].r=q2;}
	}
	sort(co+1,co+len+1,cmp);
	
	int mx=co[1].r;int ret=d(co[1].l,co[1].r);
	rep(i,2,len){
		if(mx>=co[i].l)chkmax(ret,d(min(mx,co[i].r),co[i].l));
		chkmax(mx,co[i].r);chkmax(ret,d(co[i].l,co[i].r));
	}
	chkmax(ans,ret+d(mx_l,mi_r));
	
	if(pos1==pos2){write(ans);return 0;}
	int mi=n1;
	rep2(i,len,1){
		chkmax(ans,d(mx_l,mi)+d(co[i].l,mi_r));
		chkmin(mi,co[i].r);
	} 
	chkmax(ans,d(mx_l,mi)+d(n2,mi_r));write(ans);
	return 0;
}