#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef pair<int,int> int_pair;
typedef pair<ll,ll> ll_pair;
#define N 1002
#define INF 1e9+1
string s1,s2;
int dp[N][N];


int main(){
	FOR(i,0,N)FOR(j,0,N)dp[i][j]=-1;
	cin>>s1>>s2;
	FOR(i,0,s1.size()+1){
		dp[i][0]=i;
	}
	FOR(i,0,s2.size()+1){
		dp[0][i]=i;
	}
	FOR(i,1,s1.size()+1){
		FOR(j,1,s2.size()+1){
			int a,b=1;
			if(s1[i-1]==s2[j-1])b=0;
			a=min(dp[i-1][j]+1,dp[i][j-1]+1);
			a=min(a,dp[i-1][j-1]+b);
			dp[i][j]=a;
		}
	}
	cout<<dp[s1.size()][s2.size()]<<endl;
	return 0;
}
