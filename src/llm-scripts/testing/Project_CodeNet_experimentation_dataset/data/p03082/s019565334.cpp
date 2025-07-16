#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 1000000007 
#define N 100005
#define M 1000003
#define LOG 19
#define KOK 250
#define EPS 0.0000001
using namespace std;

int n,x;
int s[N],dp[N],pt[N];
int res[205][205];

int mul(int x,int y) {
	
	return (ll)x*y%MOD;

}

int add(int x,int y) {

	x+=y;

	if(x>=MOD) x-=MOD;
	if(x<0) x+=MOD;

	return x;

}

int main() {

	scanf("%d %d",&n,&x);

	for(int i=1;i<=n;i++) scanf("%d",&s[i]);

	sort(s+1,s+1+n);

	for(int i=0;i<=n+1;i++) {

		res[i][0]=1;

		for(int j=1;j<=n+1;j++) {

			res[i][j]=mul(res[i][j-1],i+j-1);

		}

	}

	int ptr=0;

	for(int i=0;i<=x;i++) {

		while(s[ptr+1]<=i && ptr+1<=n) ++ptr;

		pt[i]=ptr;

		if(ptr==0) dp[i]=i;

		for(int j=ptr;j>=1;j--) {

			int nm=i%s[j];

			dp[i]=add(dp[i],mul(dp[nm],res[pt[nm]+1][ptr-pt[nm]-1]));

		}

	}

	dp[x]=mul(dp[x],res[ptr+1][n-ptr]);

	printf("%d",dp[x]);

}