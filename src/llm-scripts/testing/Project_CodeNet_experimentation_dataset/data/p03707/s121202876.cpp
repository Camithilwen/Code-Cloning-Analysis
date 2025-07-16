#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int n,m,q,a[2010][2010];
int po[2010][2010],ba[2010][2010];
int ob[2010][2010],zb[2010][2010];
int main(){
// 	freopen("duty.in","r",stdin);
// 	freopen("duty.out","w",stdout);
	n=read(); m=read(); q=read();
	for(int i=0;++i<=n;){
		char ch;
		for(int j=0;++j<=m;)
			ch=getchar(),a[i][j]=(ch=='1');
		ch=getchar();
	}
	for(int i=0;++i<=n;)
		for(int j=0;++j<=m;){
			po[i][j]=po[i-1][j]+po[i][j-1]-po[i-1][j-1]+a[i][j];
			ba[i][j]=ba[i-1][j]+ba[i][j-1]-ba[i-1][j-1]+(a[i][j]&a[i-1][j])+(a[i][j]&a[i][j-1]);
			ob[i][j]=ob[i][j-1]+(a[i][j]&a[i-1][j]);
		}
	for(int j=0;++j<=m;)
		for(int i=0;++i<=n;)
			zb[i][j]=zb[i-1][j]+(a[i][j]&a[i][j-1]);
	for(int i=0;++i<=q;){
		int sx=read(),sy=read(),ex=read(),ey=read();
		int Sp=po[ex][ey]-po[sx-1][ey]-po[ex][sy-1]+po[sx-1][sy-1];
		int Sb=ba[ex][ey]-ba[sx-1][ey]-ba[ex][sy-1]+ba[sx-1][sy-1];
		printf("%d\n",Sp-Sb+ob[sx][ey]-ob[sx][sy-1]+zb[ex][sy]-zb[sx-1][sy]);
	}
	return 0;
}