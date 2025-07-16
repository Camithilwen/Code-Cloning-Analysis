#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=1e5+5;

int n,ord[N];
ll val[N],l[N],u[N],b[N],s[N],x;

bool cmp(int x,int y) {return val[x]>val[y];}

ll chk_mx(ll k) {
	ll mx=0;
	ll p=k/x,q=k%x;
	if (p==n) return s[n];
	fo(i,1,n) {
		int z=ord[i];
		ll tmp=(q<=b[z])?q*l[z]:b[z]*l[z]+(q-b[z])*u[z];
		tmp+=(i<=p)?s[p+1]-val[z]:s[p];
		mx=max(mx,tmp);
	}
	return mx;
}

int main() {
	n=read();x=read();
	fo(i,1,n) b[i]=read(),l[i]=read(),u[i]=read();
	fo(i,1,n) val[i]=l[i]*b[i]+(x-b[i])*u[i];
	fo(i,1,n) ord[i]=i;sort(ord+1,ord+n+1,cmp);
	fo(i,1,n) s[i]=s[i-1]+val[ord[i]];
	ll d=0;fo(i,1,n) d+=l[i]*b[i];
	ll L=0,R=0,ans=0;fo(i,1,n) R+=b[i];
	while (L<=R) {
		ll mid=L+R>>1;
		if (chk_mx(mid)>=d) ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}