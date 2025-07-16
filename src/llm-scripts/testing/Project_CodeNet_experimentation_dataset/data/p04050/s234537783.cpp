#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105;
int n,m,a[maxn],b[maxn];
inline char nc(){
	static char buf[100000],*p1,*p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int ret=0;bool f=0;char ch=nc();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=nc();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=nc();
	return f?-ret:ret;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++) a[i]=read();
	for (int i=2;i<=m;i++)
	if(a[i]&1) swap(a[i],a[1]);
	for (int i=m-1;i>1;i--)
	if(a[i]&1) swap(a[i],a[m]);
	for (int i=2;i<m;i++)
	if(a[i]&1) return puts("Impossible")&0;
	for (int i=1;i<=m;i++)
	printf("%d",a[i]),putchar(i==m?'\n':' ');
	if(a[1]>1) b[++b[0]]=a[1]-1;
	for (int i=2;i<m;i++) b[++b[0]]=a[i];
	if(m>1){
		b[++b[0]]=2;
		if(a[m]>1) b[++b[0]]=a[m]-1;
	}else b[++b[0]]=1;
	for (int i=0;i<=b[0];i++)
	printf("%d",b[i]),putchar(!i||i==b[0]?'\n':' ');
	return 0;
}