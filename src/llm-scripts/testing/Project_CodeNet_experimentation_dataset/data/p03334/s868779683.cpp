#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
int n,d1,d2,cnt=0;
bool f[1005][1005];
inline void solve(int d){
	int b=0;
	while(!(d%4))d>>=2,++b;
	if(d&1){
		for(int i=0;i<(n<<1);++i)
			for(int j=0;j<(n<<1);++j)
				if(((i>>b)+(j>>b))&1)f[i][j]=true;
		return;
	}
	for(int i=0;i<(n<<1);++i)
		for(int j=0;j<(n<<1);++j)
			if((i>>b)&1)f[i][j]=true;
}
int main(){
	scanf("%d%d%d",&n,&d1,&d2);
	solve(d1),solve(d2);
	for(int i=0;i<(n<<1);++i)
		for(int j=0;j<(n<<1);++j)
			if(cnt<n*n&&!f[i][j])printf("%d %d\n",i,j),++cnt;
	return 0;
}