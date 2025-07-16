#include<bits/stdc++.h>
using namespace std;
template<class T>inline void read(T &re)
{
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	re=ch-48;
	while((ch=getchar())>='0'&&ch<='9')
	re=(re<<3)+(re<<1)+ch-48;
}
int n,m,Q,pt[4005][4005],eg[4005][4005];
char mp[2005][2005],s[4005][4005];
int main()
{
//	freopen("duty.in","r",stdin);
//	freopen("duty.out","w",stdout);
	read(n);read(m);read(Q);
	for(register int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
		for(register int j=1;j<=m;++j)
		s[2*i-1][2*j-1]=mp[i][j];
	}
		
	for(register int i=1;i<=n;++i){
		int x=2*i-1,y;
		for(register int j=1;j<=m;++j){
			y=2*j-1;
			if(s[x][y]=='1'){
				if(s[x+2][y]=='1')
					s[x+1][y]='2';
				if(s[x][y+2]=='1')
					s[x][y+1]='2';
			}
		}
	}
	
	for(register int i=1;i<=2*n-1;++i){
		for(register int j=1;j<=2*m-1;++j){
			pt[i][j]=(s[i][j]=='1')+pt[i-1][j]+pt[i][j-1]-pt[i-1][j-1];
			eg[i][j]=(s[i][j]=='2')+eg[i-1][j]+eg[i][j-1]-eg[i-1][j-1];
		}
	}
	int u,v,w,z,ans1,ans2;
	for(register int i=1;i<=Q;++i){
		read(u);read(v);read(w);read(z);
		u=2*u-1,v=2*v-1,w=2*w-1,z=2*z-1;
		ans1=pt[w][z]+pt[u-1][v-1]-pt[u-1][z]-pt[w][v-1];
		ans2=eg[w][z]+eg[u-1][v-1]-eg[u-1][z]-eg[w][v-1];
		printf("%d\n",ans1-ans2);
	}
}