#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
const int py=6005;
int f[6005][16005],n,Mod;
void add(int &a,int b){((a+=b)>=Mod)?(a-=Mod):0;}
int main(){
	n=read()*3;Mod=read();
	f[0][py]=1;
	for(int i=0;i<n;++i){
		for(int j=-i;j<=i;++j){
			add(f[i+1][j+py+1],f[i][j+py]);
			add(f[i+2][j+py-1],(LL)f[i][j+py]*(i+1)%Mod);
			add(f[i+3][j+py],(LL)f[i][j+py]*(i+1)*(i+2)%Mod);
		}
	}
	LL ans=0;
	for(int i=0;i<=n;++i)ans+=f[n][i+py];
	printf("%lld\n",ans%Mod);
	return 0;
}















