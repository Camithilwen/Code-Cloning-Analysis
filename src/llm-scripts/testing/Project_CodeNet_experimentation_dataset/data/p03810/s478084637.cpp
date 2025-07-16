#include <bits/stdc++.h>
using namespace std;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=1e5+50;
int n,a[N];

inline int calc_status() {
	int c1=0, c2=0;
	for(int i=1;i<=n;i++)
		(a[i]&1) ? ++c1 : ++c2;
	if(c2&1) return 1;
	else if(c1>=2) return 0;
	else {
		int g=0;
		for(int i=1;i<=n;i++) {
			if(a[i]&1) {
				if(a[i]==1) return 0;
				else --a[i];
			}
			g=__gcd(a[i],g);
		}
		for(int i=1;i<=n;i++) a[i]/=g;
		return calc_status() ? 0 : 1;
	}
}
int main() {
	n=rd();
	if(n==1) {puts("Second"); return 0;}
	for(int i=1;i<=n;i++) a[i]=rd();
	if(calc_status()==1) puts("First");
	else puts("Second");
}