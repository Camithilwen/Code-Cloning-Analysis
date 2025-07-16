// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

ll read() {
	ll X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

int main() {
	ll k=read(); int n=50;
	ll c=k/n,r=k%n;
	printf("%d\n",n);
	for (int i=1;i<=n;++i) {
		if (i<=r) printf("%lld ",n-1+c+n-(r-1));
		else printf("%lld ",n-1+c-r);
	}
	return 0;
}