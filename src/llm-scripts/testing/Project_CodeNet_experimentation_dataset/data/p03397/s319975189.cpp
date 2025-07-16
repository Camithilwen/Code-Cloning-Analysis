#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int N=3e5+10,P=1e9+7;
const int tr[][2]={{1,2},{3,4},{5,6},{1,1},{1,2},{7,2},{6,6},{5,5}};
char s[N];int dp[N][8];
inline void upd(int &x,int y){((x+=y)>=P)&&(x-=P);}
int main(){
	scanf("%s",s);int n=strlen(s);
	dp[0][0]=1;
	rep(i,0,n-1){
		rep(j,0,7){
			if(s[i]^49) upd(dp[i+1][tr[j][0]],dp[i][j]);
			if(s[i]^48) upd(dp[i+1][tr[j][1]],dp[i][j]);
		}
	}
	printf("%d\n",dp[n][2]+dp[n][6]>=P?dp[n][2]+dp[n][6]-P:dp[n][2]+dp[n][6]);
	return 0;
}