#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
    int x=0,p=1;char c=getchar();
    while (c<=32)c=getchar();
    if(c==45)p=-p,c=getchar();
    while (c>32)x=x*10+c-48,c=getchar();
    return x*p;
}
using namespace std;
//ruogu
const int N=310;
int n,k,dp[N][N][N];
char s[N];
//
int go(int l,int r,int x){
	if(l>r)return 0;
	if(l==r)return 1;
	if(dp[l][r][x]!=-1)return dp[l][r][x];
	int ans=max(go(l+1,r,x),go(l,r-1,x));
	if(s[l]==s[r])ans=max(ans,go(l+1,r-1,x)+2);
	if(x>0)ans=max(ans,go(l+1,r-1,x-1)+2);
	return dp[l][r][x]=ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&k);
	printf("%d\n",go(0,n-1,k));
	return 0;
}