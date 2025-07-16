#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
using namespace std;
#define N (1000000000+7)
//#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> Q;
 
const int inf = (int)1e9; 
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

ll dp[110][10];
ll fib[1010];

int main(void){
	int H,W,K;
	cin>>H>>W>>K;
	dp[0][1]=1;
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<1010;i++){
		fib[i] = (fib[i-1]+fib[i-2])%N;
	}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(j==1){
				dp[i][j] = (dp[i-1][j]*fib[W-1])%N;
				if(W-j>=0){
					ll t = (dp[i-1][j+1]*fib[W-j-1])%N;
					dp[i][j] = (dp[i][j]+t)%N;
				}
			}
			else{
				if(j==W){
					dp[i][j] = (dp[i-1][j]*fib[j-1])%N;
					if(j-2>=0){
						ll t = (dp[i-1][j-1]*fib[j-2])%N;
						dp[i][j] = (dp[i][j]+t)%N;
					}
				}
				else{
					ll t1 = (fib[j-2]*fib[W-j])%N;
					ll t2 = (fib[j-1]*fib[W-j-1])%N;
					ll t3 = (fib[j-1]*fib[W-j])%N;
					t1 = (dp[i-1][j-1]*t1)%N;
					t2 = (dp[i-1][j+1]*t2)%N;
					t3 = (dp[i-1][j]*t3)%N;
					dp[i][j] = ((t1+t2)%N+t3)%N;
				}
			}
		}
	}
	/*for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[H][K]<<endl;
	return 0;

}