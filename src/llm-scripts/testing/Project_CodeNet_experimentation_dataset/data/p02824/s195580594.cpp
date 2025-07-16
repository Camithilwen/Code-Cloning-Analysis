#include <cstring>
#include <algorithm>
#include <cstdio>
#define int long long
#define ri register int
#define N 100005
using namespace std;
int n,m,v,p,t=0,ans,a[N]= {0};
template <typename T> inline void read(T &x) {
    T c=getchar(),f=0;
    for (; c<48||57<c; c=getchar()) if (c=='-') f=1;
    for (x=0; 48<=c&&c<=57; c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    if (f) x=-x;
}
template <typename T> inline void print(T x) {
    if (x<0) x=-x,putchar('-');
    if (x>9) print(x/10);
    putchar(x%10+48);
}
signed main() {
	read(n),read(m),read(v),read(p),ans=p;
	for (ri i=1; i<=n; i++) read(a[i]);
	sort(a+1,a+1+n),reverse(a+1,a+1+n);
	for (ri i=p+1; i<=n; i++) {
		if (a[i]+m<a[p]) break;
		if (v<=(p-1)+(n-i+1)) ans++;
		else if ((v-p-n+i)*m<=t) ans++;
		else if (((v-p-n+i)*m-t-1)/(i-p)+1+a[p]<=a[i]+m) ans++;
		t+=a[p]-a[i];
	}
	print(ans),putchar('\n');
    return 0;
}