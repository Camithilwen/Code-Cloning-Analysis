#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	x=0;char c=getchar();bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return  x;
}
template<class t> inline void write(t x){
	if(x<0){putchar('-'),write(-x);}
	else{if(x>9)write(x/10);putchar('0'+x%10);}
}

const int N=2005;
int n,m,q,a[N][N],s[N][N],sx[N][N],sy[N][N];

void doit(){
	int x,y,xx,yy;
	read(x);read(y);read(xx);read(yy);
	int n=s[xx][yy]-s[xx][y-1]-s[x-1][yy]+s[x-1][y-1];
	int m=(sx[xx][yy-1]-sx[xx][y-1]-sx[x-1][yy-1]+sx[x-1][y-1])+(sy[xx-1][yy]-sy[x-1][yy]-sy[xx-1][y-1]+sy[x-1][y-1]);
	write(n-m);puts("");
}

signed main(){
	read(n);read(m);read(q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%1d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
			sx[i][j]=sx[i-1][j]+sx[i][j-1]-sx[i-1][j-1]+(a[i][j]+a[i][j+1]==2);
			sy[i][j]=sy[i-1][j]+sy[i][j-1]-sy[i-1][j-1]+(a[i][j]+a[i+1][j]==2);
		}
	while(q--) doit();
}