/*program from Wolfycz*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
inline char gc(){
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int frd(){
	int x=0,f=1; char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=gc())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline void print(int x){
	if (x<0)	putchar('-'),x=-x;
	if (x>9)	print(x/10);
	putchar(x%10+'0');
}
const int N=1e2;
int A[N+10];
int main(){
	int n=read(),m=read(),cnt=0;
	for (int i=1;i<=m;i++)	A[i]=read(),cnt+=A[i]&1;
	if (cnt>2){
		printf("Impossible\n");
		return 0;
	}
	for (int i=1;i<=m;i++)	if (A[i]&1)	swap(A[1]&1?A[m]:A[1],A[i]);
	if (m==1){
		if (A[1]==1){
			printf("1\n1\n1\n");
			return 0;
		}
		printf("%d\n2\n1 %d\n",A[1],A[1]-1);
		return 0;
	}
	for (int i=1;i<=m;i++)	printf("%d",A[i]),putchar(i==m?'\n':' ');
	printf("%d\n%d ",m-(A[m]==1),A[1]+1);
	for (int i=2;i<m;i++)	printf("%d ",A[i]);
	if (A[m]!=1)	printf("%d\n",A[m]-1);
	return 0;
}