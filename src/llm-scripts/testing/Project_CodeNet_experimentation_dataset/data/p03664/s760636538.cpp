//#include <bits/c++config.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
//#pragma GCC optimize(2)
using namespace std;
int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10+ch-48),ch=getchar();
	return fu?-x:x;
}
ll n,m,t1,t2,g[17][17],full[1<<16],dp[17][1<<16];
long long tot;
int main(){
	memset(dp,-0x80,sizeof(dp));
    dp[0][1]=0;
    cin>>n>>m;
    F(i,1,m){
    	cin>>t1>>t2;
    	t1--,t2--;
      	cin>>g[t2][t1];
    	tot+=g[t2][t1];
    	g[t1][t2]=g[t2][t1];
	}
	for(register int i=1;i<(1<<n);i++){
		for(ri j=1;j<n;j++){
			if(i&(1<<j)){
				for(ri k=0;k<j;k++){
					if(i&(1<<k)){
						full[i]+=g[j][k];
					}
				}
			}
		}
	}for(register int S=1;S<(1<<n);S+=2){
		for(register int i=0;i<n;i++){
			if(!(S&(1<<i)))continue;
			for(register int j=1;j<n;j++){
				if(!g[i][j]||(S&(1<<j)))continue;
				dp[j][S|(1<<j)]=max(dp[j][S|(1<<j)],dp[i][S]+g[i][j]);
			}
			ri s2=((1<<n)-1)^S;
			for(register int j=s2;j;j=(j-1)&s2){
				dp[i][S|j]=max(dp[i][S|j],dp[i][S]+full[(1<<i)|j]);
			}
		}
	}
	cout<<tot-dp[n-1][(1<<n)-1];
    return 0;
}