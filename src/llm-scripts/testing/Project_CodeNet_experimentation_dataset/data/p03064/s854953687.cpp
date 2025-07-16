#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MOD=998244353;

int adm(int x,int y){
	return (x+y)%MOD;
}
int mim(int x,int y){
	return (x-y+MOD)%MOD;
}
int t3m(int x){
	int y=(x+x)%MOD;
	return (x+y)%MOD;
}

//i番目まで使って和がjのものの個数
int dp[305][100000];
int dpx[305][100000];

int main(){
	int N;
	cin>>N;
	int a[301];
	int sum[301];
	sum[0]=0;
	rep1(i,N){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	
	dp[0][0]=1;
	rep(i,N){
		rep(j,sum[i]+1){
			dp[i+1][j]=adm(dp[i+1][j],dp[i][j]);
			dp[i+1][j]=adm(dp[i+1][j],dp[i][j]);
			dp[i+1][j+a[i+1]]=adm(dp[i+1][j+a[i+1]],dp[i][j]);
		}
	}
//	rep(j,sum[N]+1)cout<<dp[N][j]<<" ";
//  	cout<<endl;
  
  	dpx[0][0]=1;
	rep(i,N){
		rep(j,sum[i]+1){
			dpx[i+1][j]=adm(dpx[i+1][j],dpx[i][j]);
			dpx[i+1][j+a[i+1]]=adm(dpx[i+1][j+a[i+1]],dpx[i][j]);
		}
	}
//	rep(j,sum[N]+1)cout<<dpx[N][j]<<" ";
//  	cout<<endl;
  
	int al=1;
	rep(i,N){
		al=t3m(al);
	}
	int ans=al;
	int h=sum[N]/2;
	
	if(sum[N]%2==1){
		int ng=0;
		for(int i=h+1;i<=sum[N];i++){
			ng=adm(ng,dp[N][i]);
		}
		ng=t3m(ng);
		ans=mim(ans,ng);
	}
	else{
		int ng=0;
		for(int i=h;i<=sum[N];i++){
			ng=adm(ng,dp[N][i]);
		}
		ng=t3m(ng);
		int cv=t3m(dpx[N][h]);
		ans=adm(ans,cv);
		ans=mim(ans,ng);
	}
	
	cout<<ans<<endl;
	
}