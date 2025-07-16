#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

//dp[i][j][k],i番目の高さで,左からj列目、k：見ている箇所の左側に橋がかかっている。
lli dp[110][10];

signed main(){

	lli h,w,k;
	cin>>h>>w>>k;
	dp[0][0]=1;

	REP(i,1,h+1){
		REP(bit,0,(1LL)<<(w-1)){
			if(DEBUG)cout<<"bit="<<bit<<endl;
			
			//cout<<endl;
			bool ok=false;
			REP(j,0,w){
				//cout<<(bit&(1LL<<j))<<" ";
				if(bit&(1LL<<j) && bit&(1LL<<(j+1))){
					ok=true;
					break;
				}
			}
			if(ok)continue;
			REP(j,0,w+1){
				bool flag=false;
				if(bit&(1LL<<j)){
					dp[i][j+1] += dp[i-1][j];
					dp[i][j]   += dp[i-1][j+1];
					flag=true;
				}
				else{
					dp[i][j] += dp[i-1][j];
				}

				dp[i][j]%=MOD;
				dp[i][j+1]%=MOD;
				if(flag)j++;
			}
		}
	}

	if(DEBUG){
		cout<<"show"<<endl;
		REP(i,0,h+1){
			REP(j,0,w){
				cout<<dp[i][j]%MOD<<" ";
			}
			cout<<endl;
		}
	}

	cout<<dp[h][k-1]%MOD<<endl;

	return 0;
 
}