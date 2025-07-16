#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,x; ll s[maxn],S;
struct node {
	int l,r,a; ll t;
	void init() {
		read(a); read(l); read(r);
		t=(ll)a*l+(ll)(x-a)*r;
		S-=(ll)l*a;
	}
} d[maxn];
bool cmp(node A,node B) {
	return A.t>B.t;
}
bool solve(ll mid) {
	ll q=mid/x,r=mid-q*x,tmp;
	if (q==n) return 1;
	for (int i=1;i<=n;i++) {
		tmp=S;
		if (i<=q) tmp+=s[q+1]-d[i].t;
		else tmp+=s[q];
		if (r>=d[i].a) tmp+=(ll)d[i].l*d[i].a+(r-d[i].a)*d[i].r;
		else tmp+=r*d[i].l;
		if (tmp>=0) return 1;
	} return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(x);
	for (int i=1;i<=n;i++) d[i].init();
	sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+d[i].t;
	ll l=0,r=(ll)x*n,mid,res;
	while (l<=r) {
		mid=(l+r)/2;
		if (solve(mid)) r=mid-1,res=mid;
		else l=mid+1;
	}
	printf("%lld\n",res);
	return 0;
}