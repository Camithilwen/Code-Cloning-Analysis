#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,m,sum,s,a[maxn],b[maxn];
char S[maxn];
int N,id[maxn],d[maxn],tot;
bool cmpa(int x,int y) { return a[x]<a[y]; }
bool cmpb(int x,int y) { return b[x]>b[y]; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		scanf("%s",S+1);
		m=strlen(S+1);
		s=0;
		for (int j=1;j<=m;j++) {
			if (S[j]=='(') s++; else s--;
			a[i]=max(a[i],-s);
		}
		sum+=s;
		s=0;
		for (int j=m;j>=1;j--) {
			if (S[j]=='(') s++; else s--;
			b[i]=max(b[i],s);
		}
		//printf("%d %d\n",a[i],b[i]);
	}
	if (sum!=0) { printf("No\n"); return 0; }
	
	sum=0;
	for (int i=1;i<=n;i++) if (b[i]>=a[i]) d[++tot]=i;
	sort(d+1,d+tot+1,cmpa);
	for (int i=1;i<=tot;i++) id[++N]=d[i];
	tot=0;
	for (int i=1;i<=n;i++) if (b[i]<a[i]) d[++tot]=i;
	sort(d+1,d+tot+1,cmpb);
	for (int i=1;i<=tot;i++) id[++N]=d[i];
	for (int i=1;i<=N;i++) {
		if (sum-a[id[i]]<0) { printf("No\n"); return 0; }
		sum+=b[id[i]]-a[id[i]];
	}
	printf("Yes\n");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/