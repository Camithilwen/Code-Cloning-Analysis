#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define id(x,lev) x*52+lev
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}
int n,su = 0,a[330],dp[90020] = {0},dp2[90020];
int main() {
	read(n);
	dp[0] = dp2[0] = 1;
	int ans = pow(3,n);
	for(int i=0;i<n;i++){
		read(a[i]);
		su+=a[i];
		for(int j=su;j>=0;j--){
			dp[j] = add(dp[j],dp[j]);
			if(j>=a[i]){
				dp[j] = add(dp[j],dp[j-a[i]]);
				dp2[j] = add(dp2[j],dp2[j-a[i]]);
			}
		}
	}
	for(int i=((su+1)/2);i<=su;i++){
		ans = sub(ans,mul(3,dp[i]));
	}
//	cout<<ans<<endl;
	if(su%2== 0){
		ans = add(ans,mul(dp2[su/2],3));
	}
	cout<<ans<<endl;
	return 0;
}
