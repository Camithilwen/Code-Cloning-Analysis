#include <bits/stdc++.h>
#define cal(x,y) (x=x>y?x:y)
using namespace std;
const int N=350;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
int f[N][N][N],n,k;
char s[N];
int main(){
    scanf("%s%d",s+1,&k);
    n=strlen(s+1);
    int ans=0;
    for (int i=1; i<=n; ++i)
	for (int j=n; j>=i; --j)
	    for (int l=k; ~l; --l){
		cal(f[i+1][j][l],f[i][j][l]);
		cal(f[i][j-1][l],f[i][j][l]);
		cal(f[i+1][j-1][l],f[i][j][l]+(s[i]==s[j]));
		if (l) cal(f[i+1][j-1][l-1],f[i][j][l]+1);
	    }
    for (int i=1; i<=n; ++i)
	for (int j=0; j<=k; ++j){
	cal(ans,f[i+1][i-1][j]*2-1);
	cal(ans,f[i+1][i][j]*2);
    }
    cout<<ans;
    return 0;
}
