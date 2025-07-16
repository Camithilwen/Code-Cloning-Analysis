#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1001000;
int ii,i,j,k,l,n,m,ch,Last,ans;
char s[N],t[N],f[N];
struct cc { int x,l,r;} A[N];
int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for (i=1;i<=n;i++) if (s[i]!=t[i]) break;
	if (i>n) return puts("0"),0;
	Last=n;
	for (i=n;i;i--) {
		j=i;
		while (j && t[j-1]==t[i]) j--;
		k=min(j,Last);
		while (k && s[k]!=t[j]) k--;
		if (!k) return puts("-1"),0;
		A[k].x=k;
		A[k].l=j;A[k].r=i;
		Last=k-1;
		i=j;
	}
	for (i=1;i<=n;i++) if (A[i].x) A[++m]=A[i];
	ans=1;f[m]=1;j=m+1;
	for (i=m-1;i;i--) {
		while (j>i && A[j-1].x-(j-1-i)>=A[i].r) j--;
		if (j-i>ans) ans=j-i;
	}
	printf("%d\n",ans);
}