#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=303,mod=1e9+7;
int n;
int cnt[4];
double dp[N][N][N],ev[N][N][N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int a;cin>>a;++cnt[a];
	}
	dp[cnt[1]][cnt[2]][cnt[3]]=1;
	for(int k=n;k>=0;--k)
		for(int j=n;j>=0;--j)
			for(int i=n;i>=0;--i)
				if(i||j||k){
					double pwaste=double(n-(i+j+k))/n;
					double evwaste=pwaste/(1-pwaste)+1;
					ev[i][j][k]+=evwaste*dp[i][j][k];
					if(i)dp[i-1][j][k]+=dp[i][j][k]*i/(i+j+k);
					if(j)dp[i+1][j-1][k]+=dp[i][j][k]*j/(i+j+k);
					if(k)dp[i][j+1][k-1]+=dp[i][j][k]*k/(i+j+k);
					if(i)ev[i-1][j][k]+=ev[i][j][k]*i/(i+j+k);
					if(j)ev[i+1][j-1][k]+=ev[i][j][k]*j/(i+j+k);
					if(k)ev[i][j+1][k-1]+=ev[i][j][k]*k/(i+j+k);
				}
	cout<<setprecision(10)<<fixed<<ev[0][0][0]<<endl;
}
