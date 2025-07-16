#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int N=2e6;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int s1[N],s2[N];
int L[N],R[N],st[N];
int main()
{
	int n=gi(),i,j,top=0,ans=0;char c;
	for (i=1;i<=n;s1[i++]=c-'a') while ((c=getchar())<'a');
	for (i=1;i<=n;s2[i++]=c-'a') while ((c=getchar())<'a');
	for (i=n;i&&s1[i]==s2[i];i--);if (!i) return puts("0"),0;
	for (i=j=n;i;L[j]=i--) {
		while (j&&s1[j]!=s2[i]) j--;
		if (!j) return puts("-1"),0;
		if (!R[j]) R[j]=i,st[++top]=j;
		j-=i==j;
	}
	reverse(st+1,st+1+top);
	for (i=j=1;i<=top;i++) {
		while (j<top&&st[j+1]-(j-i+1)<R[st[i]]) j++;
		ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
