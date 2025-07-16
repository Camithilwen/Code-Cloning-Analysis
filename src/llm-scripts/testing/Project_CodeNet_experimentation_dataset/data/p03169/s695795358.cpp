#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define f(i,n) for(int i=0;i<n;i++)
const int maxn=305;
double dp[maxn][maxn][maxn];
double recur(int k, int b, int c,int n){
	if(dp[k][b][c]>=0)return dp[k][b][c];
	if(k==0&&b==0&&c==0)return 0.0;
	double res=0.0;
	// dp[k][b][c]=0.0;
	if(k>0)res+=(k)*recur(k-1,b,c,n);
	if(b>0)res+=(b)*recur(k+1,b-1,c,n);
	if(c>0)res+=(c)*recur(k,b+1,c-1,n);
	// dp[k][b][c]/=(n-k-c-b);
	res+=n;
	res*=1.0/(k+b+c);
	return dp[k][b][c]=res;
}
int main() {

	cout<<fixed<<setprecision(10);
	int n;
	cin>>n;
	vector<int>a(4,0);
	f(i,n){int x;
	cin>>x;
	a[x]++;
	}
	memset(dp, -1, sizeof(dp));
	cout<<fixed<<setprecision(9)<<recur(a[1],a[2],a[3],n)<<endl;

	return 0;
}
