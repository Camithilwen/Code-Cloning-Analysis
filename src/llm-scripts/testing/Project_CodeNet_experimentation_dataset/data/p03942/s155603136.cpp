#include <cstdio>
using namespace std;
#define REP(a,b,c) for(int a=b;a<=c;++a)
#define RREP(a,b,c) for(int a=b;a>=c;--a)

char s[1000005],t[1000005];
int n,x[1000005],l,r,ans,q,j;

int main() {
	scanf("%d%s%s",&n,s+1,t+1);
	j=n; l=1; r=0; ans=0; q=0;
	RREP(i,n,1) {
		if(j>i) --j;
		if(s[j]==t[i]) continue;
		while(j&&s[j]!=t[i]) --j;
		if(!j) {puts("-1"); return 0;}
		--q; x[++r]=j-q; while(l<=r&&x[l]+q>=i) ++l;
		if(r-l>=ans) ans=r-l+1;
	} printf("%d\n",ans); return 0;
}	