#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)
#define mod2 998244353

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}
int mod_pow(int x, int y, int m = mod) {
	int res = 1;
	x %= m;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int perm[1000005];
void init_perm(){
	perm[0]=1;
	REP(i,1000005)perm[i]=perm[i-1]*i%mod;
}
int nCk(int x,int y){
	if(x<y)return 0;
	return perm[x]*mod_pow(perm[x-y],mod-2)%mod*mod_pow(perm[y],mod-2)%mod;
}
int N,A,B,C,D;
int dp[1005][1005];
signed main(){
    init_perm();
    cin>>N>>A>>B>>C>>D;
    dp[0][1]=1;
    rep(i,N){
        REP(j,N){
            dp[i][j]%=mod;
            dp[i][j+1]+=dp[i][j];
        }
        for(int j=A;j<=B;j++){
            int ans=1,rem=N-i;
            REP(k,D+1){
                if(i+j*k>N)break;
                ans*=nCk(rem,j);
                ans%=mod;
                rem-=j;
                if(k>=C){
                    dp[i+j*k][j+1]+=dp[i][j]*ans%mod*mod_pow(perm[k],mod-2)%mod;
                    dp[i+j*k][j+1]%=mod;
                }
            }
        }
    }
    int ans=0;
    rep(i,N+2){
        //cout<<dp[N][i]<<endl;
        ans+=dp[N][i]%mod;
    }
    cout<<ans%mod<<endl;
}