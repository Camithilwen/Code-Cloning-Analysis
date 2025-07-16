#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define repd(i,j,k) for(int i=j;i>=k;--i)
#define pb push_back
#define db double
#define mp make_pair
#define mp3(a,b,c) mp(mp(a,b),c)
#define pii pair<int,int>
#define piii pair<pii,int>
#define fr first
#define se second
#define ll long long
#define ull unsigned long long
#define pbc(x) __builtin_popcount(x)
#define clr(x) memset(x,0,sizeof x)
#define SIZE(x) (int)(x.size())
const int mod=1e9+7;
IL int pls(int x,int y){x+=y;return x>=mod?x-mod:x;}
IL int dec(int x,int y){x-=y;return x<0?x+mod:x;}
IL int mul(int x,int y){return 1ll*x*y%mod;}
IL int mul(int x,int y,int z){return mul(mul(x,y),z);}
IL int mul(int x,int y,int z,int p){return mul(mul(x,y),mul(z,p));}
IL void add(int &x,int y){x+=y;x=(x>=mod)?x-mod:x;}
IL int fpw(int x,int y,int r=1){for(;y;y>>=1,x=mul(x,x))if(y&1)r=mul(r,x);return r;}
IL int inv(int x){return fpw(x,mod-2);}
IL int gi(){int x;int _w=scanf("%d",&x);return x;}
IL void gi(int &x){int _w=scanf("%d",&x);}
IL void write(int x){printf("%d\n",x);}
void chkmax(int &x,int y){x=(x>y)?x:y;}
void chkmin(int &x,int y){x=(x<y)?x:y;}
const int INF=0x3f3f3f3f;
template<typename T>IL void debug(T x){cerr<<x;return;}
/* --------------------------------------------------------------------------------------------------------- */
const int maxn=1e5+10;
int n,m,a[maxn];
namespace sub1{
	IL bool check(){
		rep(i,1,m)if(a[i]&1)return false;
		return true;
	}
	IL void work(){
		rep(i,1,m)printf("%d ",a[i]);
		putchar('\n');
		vector<int>b;
		b.pb(1);
		rep(i,1,m-1)b.pb(a[i]);
		b.pb(a[m]-1);
		printf("%d\n",b.size());
		rep(i,0,b.size()-1)printf("%d ",b[i]);
	}
}
namespace sub2{
	IL bool check(){
		int cnt=0;
		rep(i,1,m)if(a[i]&1)cnt++;
		return cnt==1;
	}
	IL void work(){
		int pos;
		rep(i,1,m)if(a[i]&1)pos=i;
		swap(a[m],a[pos]);
		rep(i,1,m)printf("%d ",a[i]);
		putchar('\n');
		vector<int>b;
		b.pb(1);
		rep(i,1,m-1)b.pb(a[i]);
		if(a[m]!=1)b.pb(a[m]-1);
		printf("%d\n",b.size());
		rep(i,0,b.size()-1)printf("%d ",b[i]);
	}
}
namespace sub3{
	IL bool check(){
		int cnt=0;
		rep(i,1,m)if(a[i]&1)cnt++;
		return cnt==2;
	}
	IL void work(){
		int pos;
		rep(i,1,m)if(a[i]&1)pos=i;
		swap(a[1],a[pos]);
		rep(i,2,m)if(a[i]&1)pos=i;
		swap(a[m],a[pos]);
		rep(i,1,m)printf("%d ",a[i]);
		putchar('\n');
		vector<int>b;
		b.pb(a[1]+1);
		rep(i,2,m-1)b.pb(a[i]);
		if(a[m]!=1)b.pb(a[m]-1);
		printf("%d\n",b.size());
		rep(i,0,b.size()-1)printf("%d ",b[i]);
	}
}
int main(){
#ifdef LOCAL
	freopen("/home/noilinux/Desktop/input.txt","r",stdin);
#endif
	n=gi(),m=gi();
	rep(i,1,n)a[i]=gi();
	if(sub1::check())sub1::work();else if(sub2::check())sub2::work();
	else if(sub3::check())sub3::work();else printf("Impossible\n");
	return 0;
}