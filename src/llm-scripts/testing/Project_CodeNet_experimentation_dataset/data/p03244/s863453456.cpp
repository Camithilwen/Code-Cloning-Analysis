/*====Corycle====*/
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<vector>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<map>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],num[2][N],f[2][2],g[2][2];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){a[i]=read();num[i&1][a[i]]++;}
	for(int t=0;t<2;t++){
		for(int i=1;i<N;i++){
			if(f[t][0]<=num[t][i]){
				f[t][1]=num[t][g[t][1]=g[t][0]];
				f[t][0]=num[t][g[t][0]=i];
			}
			else if(f[t][1]<=num[t][i]){
				f[t][1]=num[t][g[t][1]=i];
			}
		}
	}
	if(g[0][0]!=g[1][0])printf("%d\n",n-f[0][0]-f[1][0]);
	else printf("%d\n",min(n-f[0][0]-f[1][1],n-f[0][1]-f[1][0]));
	return 0;
}