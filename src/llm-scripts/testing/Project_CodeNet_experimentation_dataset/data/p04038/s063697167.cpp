#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define p 1000000007
using namespace std;
namespace ywy{
	inline ll mi(int a,int b){
		ll ans=1,tmp=a;while(b){
			if(b&1)ans=(ans*tmp)%p;tmp=(tmp*tmp)%p;b>>=1;
		}return(ans);
	}int jc[5000001],jcny[5000001],dp[2022][2022];
	inline ll cnm(int n,int m){
		if(n<m)return(0);ll cjr=jc[n];cjr*=jcny[m];cjr%=p;cjr*=jcny[n-m];return(cjr%p);
	}
	inline void pre(int n){
		jc[0]=1;for(register int i=1;i<=n;i++)jc[i]=((ll)jc[i-1]*i)%p;jcny[n]=mi(jc[n],p-2);
		for(register int i=n-1;i>=0;i--)jcny[i]=((ll)jcny[i+1]*(i+1))%p;
	}
	void ywymain(){
		int n,k;cin>>n>>k;if(k==1){
			cout<<1<<endl;return;
		}pre(n*k);dp[1][0]=dp[1][1]=1;for(register int i=2;i<=n;i++){
			for(register int j=i;j>=0;j--){
				if(!j)dp[i][j]=dp[i][j+1];else{
					dp[i][j]=(dp[i][j+1]+((dp[i-1][j-1]*(ll)i)%p)*cnm(i*k-j-1,k-2))%p;
				}
			}
		}cout<<dp[n][0]<<endl;
	}
}
int main(){
	ywy::ywymain();return(0);
}