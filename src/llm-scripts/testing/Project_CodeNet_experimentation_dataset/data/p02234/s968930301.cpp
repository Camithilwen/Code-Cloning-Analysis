#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int n;//計算する行列の数
const int MAX_N =110;
int dp[MAX_N][MAX_N];//dp[i][j]:=Ai...Ajの計算に必要な最小のコスト
pii A[MAX_N];//行列firstを行secondを列とする。
void init(){
	for(int i =0; i < n;i++){
		for(int j = 0;j < n;j++){
			dp[i][j]=INF;
		}
	}
	for(int i =0;i < n;i++){
		dp[i][i]=0;
	}
}

int solve(){
	for(int k =1;k <n;k++){
		for(int i =0;i <n-k;i++){
			for(int j =i;j <i+k;j++){
				int sz =A[i].first*A[j].second*A[i+k].second;
				dp[i][i+k]=
				min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]+sz);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	cin>>n;
	init();
	for(int i =0;i < n;i++){
		cin>>A[i].first>>A[i].second;
	}
	cout <<solve()<<endl;
	return 0;
}