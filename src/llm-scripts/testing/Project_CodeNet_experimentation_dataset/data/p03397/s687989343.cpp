#include<bits/stdc++.h>
#define ll long long
#define re register
#define ull unsigned ll
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*t;
}
const int N=3e5+5;
const int P=1e9+7;
char s[N];
int n,Ans,f[N][3][3];
int Mod(int x){return x>=P?x-P:x;}
void Mod(int &x,int y){(x+=y)>=P?x-=P:0;}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1),n=strlen(s+1);
	f[0][0][0]=1;
	for(int i=1,tp=0;i<=n;i++){
		for(int x=0;x<=2;x++)
		for(int y=0;y<=2;y++)
		if((tp=f[i-1][x][y])){
			if(s[i]!='0'){//1
				if(y==0)Mod(f[i][min(2,x+1)][0],tp);
				else Mod(f[i][x][y-1],tp);
			}
			if(s[i]!='1'){//0
				if(y==2)Mod(f[i][x][1],tp);
				else Mod(f[i][x][y+1],tp);
			}
		}
	}
	for(int x=0;x<=2;x++)
	for(int y=0;y<=2;y++)if(x>=y)Mod(Ans,f[n][x][y]);
	printf("%d",Ans);
	return 0;
}
