#include<bits/stdc++.h> 
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
typedef long long ll;
using namespace std;
const int maxn=2e3+5;
char S[maxn];
int s[maxn][maxn],a[maxn][maxn];
int i,j,H,W,ans,h[maxn][maxn],t,q[maxn][2],cnt,len;
int main(){
	scanf("%d%d",&H,&W);
	fo(i,1,H) {
		scanf("%s",S+1);
		fo(j,1,W) s[i][j]=S[j]=='#';
	}
	ans=max(H,W);
	if (H==1||W==1) return printf("%d\n",ans),0;
	H--,W--;
	fo(i,1,H){
		cnt=0;
		fo(j,1,W){
			t=s[i][j]^s[i][j+1]^s[i+1][j]^s[i+1][j+1]^1;
			len=h[i][j]=(t)?h[i-1][j]+1:0;
			for(;cnt&&q[cnt][0]>len;cnt--) ans=max(ans,(q[cnt][0]+1)*(j-q[cnt-1][1]));
			q[++cnt][0]=len,q[cnt][1]=j;
		}
		for(;cnt;cnt--) ans=max(ans,(q[cnt][0]+1)*(W-q[cnt-1][1]+1));
	}
	printf("%d\n",ans);
}