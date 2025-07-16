#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=605;

int n,d1,d2;
bool vis[N][N];

bool fill(int d) {
	int t=0;
	for(;!(d&3);d>>=2) t++;
	if ((d&3)==1) fo(i,0,n-1) fo(j,0,n-1) vis[i][j]|=((i>>t)+(j>>t))&1;
	else fo(i,0,n-1) fo(j,0,n-1) vis[i][j]|=(i>>t)&1;
}

int main() {
	scanf("%d",&n);n<<=1;
	scanf("%d%d",&d1,&d2);fill(d1);fill(d2);
	int m=n*n>>2;
	fo(i,0,n-1) fo(j,0,n-1)
		if (!vis[i][j]) {
			printf("%d %d\n",i,j);
			if (!(--m)) return 0;
		}
	return 0;	
}