#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],match[N];
char s[N],t[N];
int main()
{
	scanf("%d%s%s",&n,s+1,t+1);
	if (!strcmp(s+1,t+1)) return puts("0"),0;
	for (int p=n,q=n;p;p--){
		while (t[p]==t[p-1]) p--;
		while (q&&(q>p||s[q]!=t[p])) q--;
		if (!q) return puts("-1"),0;
		match[p]=q;
	}
	for (int i=1;i<=n;i++)
		if (match[i]) m++,a[m]=match[i],b[m]=i;
	a[m+1]=b[m+1]=n+1;
	int ans=0,Max=0;
	for (int i=1;i<=m;i++)
		for (int j=a[i];j<a[i+1]-1;j++)
			if (s[j]!=s[j+1]) ans=1;
	for (int i=1;i<=m;i++){
		int l=0,r=m+1-i;
		while (l<r){
			int mid=(l+r)>>1;
			if (a[i+mid]-mid>=b[i]) r=mid;else l=mid+1;
		}
		Max=max(Max,l);
	}
	printf("%d\n",ans+Max);
	return 0;
}