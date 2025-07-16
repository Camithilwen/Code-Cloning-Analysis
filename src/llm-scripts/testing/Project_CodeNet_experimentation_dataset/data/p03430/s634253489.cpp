#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

char str[305];
int dp[305][305][305];
void upd(int &a,int b){
	a =max(a,b);
}
int main() {
	cin>>(str+1);
	int n = strlen(str+1);
	int lim;
	cin>>lim;
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			for(int k=0;k<=lim;k++){
				upd(dp[i+1][j][k],dp[i][j][k]);
				upd(dp[i][j-1][k],dp[i][j][k]);
				if(str[i] == str[j]){
					upd(dp[i+1][j-1][k],dp[i][j][k]+1);
				}else{
					upd(dp[i+1][j-1][k+1],dp[i][j][k]+1);
				}
			}
		}
	}
	for(int i=0;i<=n+1;i++){
		for(int j=n+1;j>=0;j--){
			for(int k=0;k<=lim;k++){
				if(i == j+1)ans = max(ans,dp[i][j][k]*2);
				if(i-1 == j+1)ans = max(ans,dp[i][j][k]*2-1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
