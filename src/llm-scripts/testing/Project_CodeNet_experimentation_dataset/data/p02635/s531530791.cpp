#include<bits/stdc++.h>
#define cs const
#define pb push_back
using namespace std;
cs int Mod = 998244353;
int add(int a, int b){ return a + b >= Mod ? a + b - Mod : a + b; }
int dec(int a, int b){ return a - b < 0 ? a - b + Mod : a - b; }
void Add(int &a, int b){ a = add(a,b); }
cs int N = 305;
int n, K; char S[N];
int a[N], len, dp[2][N][N];
int main(){
	#ifdef FSYolanda
	freopen("1.in","r",stdin);
	#endif
	scanf("%s%d",S+1,&K); 
	K=min(K,n=strlen(S+1));S[n+1]='0';
	for(int i=1,pt=0; i<=n+1; i++){
		if(S[i]=='1')continue;
		a[++len]=i-pt-1; pt=i;
	} int now=0, nxt=1;
	dp[0][0][0]=1;
//	for(int i=1; i<=len; i++)
//	cout << a[i] << " "; cout << endl;
	for(int i=1; i<=len; i++){
		memset(dp[nxt],0,sizeof(dp[nxt]));
		for(int k=0; k<=K; k++){
			static int sm[N]; sm[0]=0;
			for(int l=1; l<=K; l++)
			sm[l]=add(sm[l-1],dp[now][l][k]);
			for(int j=0; j<=K; j++)
			Add(dp[nxt][j][k],dec(sm[min(K,j+a[i])],sm[j])); 
		} static int sm[N][N];
		for(int j=0; j<=K; j++)
		for(int k=0; k<=K; k++){
			sm[j][k] = dp[now][j][k];
			if(j && k) Add(sm[j][k],sm[j-1][k-1]);
			Add(dp[nxt][j][k],sm[j][k]);
		} swap(now, nxt);
	} 
	int ans = 0;
	for(int j=0; j<=K; j++)
	Add(ans, dp[now][0][j]);
	cout << ans; return 0;
}