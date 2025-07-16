#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
const int N=100005;
int n,a[4][N],b[N],ans[2];
void NO() {puts("No");exit(0);}
int main()
{
	n=read();
	for(RI i=1;i<=3;++i)
		for(RI j=1;j<=n;++j) {
			a[i][j]=read();
			int x=(a[i][j]-1)%3+1,y=(a[i][j]+2)/3;
			if((i!=2&&x==2)||(i==2&&x!=2)) NO();
			if((j&1)^(y&1)) NO();
		}
	for(RI j=1;j<=n;++j) {
		int x=(a[1][j]-1)%3+1,y=(a[1][j]+2)/3;
		if((a[2][j]+2)/3!=y||(a[3][j]+2)/3!=y) NO();
		if(x==1&&(a[3][j]-1)%3+1!=3) NO();
		if(x==3&&(a[3][j]-1)%3+1!=1) NO();
		if(x==3) ans[j&1]^=1;
		b[j]=y;
	}
	for(RI i=1;i<=n;++i)
		while(b[i]!=i) ans[(i&1)^1]^=1,swap(b[i],b[b[i]]);
	if(ans[0]||ans[1]) NO();
	puts("Yes");
	return 0;
}