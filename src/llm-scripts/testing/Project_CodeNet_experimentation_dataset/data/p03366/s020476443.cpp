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

int n,s,x[N];
ll t[N],p[N];

void solve(int l,int r) {
	if (x[r]<s) {
		fo(i,l,r) t[i]=s-x[i];
		return;
	}
	if (x[l]>s) {
		fo(i,l,r) t[i]=x[i]-s;
		return;
	}
	if (p[l]>=p[r]) {
		p[l]+=p[r];
		solve(l,r-1);
		t[r]=t[l]+x[r]-x[l];
	} else {
		p[r]+=p[l];
		solve(l+1,r);
		t[l]=t[r]+x[r]-x[l];
	}
}

int main() {
	n=read();s=read();
	fo(i,1,n) x[i]=read(),p[i]=read();
	solve(1,n);
	printf("%lld\n",max(t[1],t[n]));
	return 0;
}