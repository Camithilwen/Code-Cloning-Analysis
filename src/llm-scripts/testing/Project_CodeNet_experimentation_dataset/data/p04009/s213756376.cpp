#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=101;
char s[N];
short g[N][N],f[N][N],v[N][N][N][N];
inline void upd(short &x,short y) {x=max(x,y);}
int main() {
    int n,m,x,y,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
	scanf("%s",s+1);
	for(int j=1;j<=m;j++) {
	    if(s[j]=='E') x=i,y=j;
	    int t=(s[j]=='o');
	    f[i][j]=f[i][j-1]+t,g[i][j]=g[i-1][j]+t;
	}
    }
    memset(v,-1,sizeof(v));
    v[0][0][0][0]=0;
    for(int i=0;i<x;i++)
	for(int j=0;x+j<=n;j++)
	    for(int p=0;p<y;p++)
		for(int q=0;y+q<=m;q++) {
		    int d=v[i][j][p][q];
		    if(d==-1) continue;
		    ans=max(ans,d);
		    if(j+1<x-i) upd(v[i+1][j][p][q],d+f[x-i-1][min(y+q,m-p)]-f[x-i-1][max(y-p,q+1)-1]);
		    if(x+j<n-i) upd(v[i][j+1][p][q],d+f[x+j+1][min(y+q,m-p)]-f[x+j+1][max(y-p,q+1)-1]);
		    if(q+1<y-p) upd(v[i][j][p+1][q],d+g[min(x+j,n-i)][y-p-1]-g[max(x-i,j+1)-1][y-p-1]);
		    if(y+q<m-p) upd(v[i][j][p][q+1],d+g[min(x+j,n-i)][y+q+1]-g[max(x-i,j+1)-1][y+q+1]);
		}
    cout<<ans;
    return 0;
}