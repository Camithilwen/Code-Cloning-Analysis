#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define rr register
using namespace std;
const int d[10]={6,2,5,5,4,5,6,3,7,6};
int m,n,x[10],f[10011];
inline signed iut(){
	rr int ans=0; rr char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) ans=(ans<<3)+(ans<<1)+(c^48),c=getchar();
	return ans;
}
inline signed max(int a,int b){return a>b?a:b;}
signed main(){
	m=iut(),n=iut(),memset(f,0xcf,sizeof(f));
	for (rr int i=1;i<=n;++i) x[i]=iut();
	sort(x+1,x+1+n),reverse(x+1,x+1+n),f[0]=0;
	for (rr int i=1;i<=n;++i)
	for (rr int j=d[x[i]];j<=m;++j)
	    f[j]=max(f[j],f[j-d[x[i]]]+1);
	while (m){
		for (rr int i=1;i<=n;++i)
		if (m>=d[x[i]]&&f[m]==f[m-d[x[i]]]+1){
			putchar(x[i]+48),m-=d[x[i]];
			break;
		}
	}
	return !putchar(10);
}