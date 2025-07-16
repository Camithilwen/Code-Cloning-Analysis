#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
using namespace std;
const int N=105;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,a[N],pos[N],cnt;
int main(){
	n=read(),m=read();
	inc(i,1,m) a[i]=read();
	inc(i,1,m) if(a[i]&1) pos[++cnt]=i;
	if(cnt>2) return puts("Impossible"),0;
	if(pos[1]) swap(a[1],a[pos[1]]);
	if(pos[2]) swap(a[m],a[pos[2]]);
	if(m==1&&a[1]==1) return printf("1\n1\n1"),0;
	inc(i,1,m) printf("%d ",a[i]);
	puts("");
	if(m==1) return printf("2\n1 %d",n-1),0;
	a[1]++,a[m]--;
	if(!a[m]) m--;
	printf("%d\n",m);
	inc(i,1,m) printf("%d ",a[i]);
}