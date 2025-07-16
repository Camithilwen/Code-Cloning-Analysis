#include<bits/stdc++.h>
#define rint register int
using namespace std;
inline int read(){
	int s=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return f?s:-s;
}
const int Mod=1e9+7;
int n,X,Y,Z,ed,ans=1;
int f[50][1<<18];
int main(){
	n=read(); X=read(); Y=read(); Z=read();
	ed=(1<<X+Y+Z-1)|(1<<Y+Z-1)|(1<<Z-1);
	f[0][0]=1;
	for(rint i=1;i<=n;++i,ans=1ll*ans*10%Mod)
		for(rint S=0;S<(1<<X+Y+Z);++S){
			if(!f[i-1][S]) continue;
			for(rint j=1;j<=10;++j){
				int now=(S<<j)|(1<<j-1);
				now=now&((1<<X+Y+Z)-1);
				if((now&ed)!=ed) f[i][now]=1ll*(f[i][now]+f[i-1][S])%Mod;
			}
		}
	for(rint S=0;S<(1<<X+Y+Z);++S)
		if((S&ed)!=ed) ans=1ll*(ans-f[n][S]+Mod)%Mod;
	printf("%d",ans); 
	return 0;
}