#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<stack>
#include<queue>
#include <iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

#define N 262144
ll dp[2][2*N+5];
int n,q,a,b;

#define INM 100000000000000000LL
//0-index
void update(int id,int k,ll a)
{
	k += N-1;
	dp[id][k] = a;
	while(k > 0)
	{
		k = (k-1)/2;
		dp[id][k] = min(dp[id][k*2+1],dp[id][k*2+2]);
	}
}


ll query(int id,int a,int b,int k=0,ll l=0,ll r=N)
{
	if(r <= a || b <= l)return INM;
	if(a <= l && r <= b)return dp[id][k];
	else
	{
		ll vr = query(id,a,b,k*2+1,l,(l+r)/2);
		ll vl = query(id,a,b,k*2+2,(l+r)/2,r);
		return min(vr,vl);
	}
}

int main()
{
	cin >> n >> q >> a >> b;
	REP(i,2)REP(j,N)update(i,j,INM);
	
	vector<int> que;que.PB(a);
	
	REP(i,q)
	{
		int tmp;cin >> tmp;que.PB(tmp);
	}
	
	update(0,b,b);
	update(1,b,n-b);
	
	//cout  << query(1,0,n+1) << endl;
	
	ll sum = 0;
	for(int i = 1;i <= q;i++)
	{
		ll tmp = abs(que[i-1]-que[i]);
		sum += tmp;
		
		ll mi = min(query(1,0,que[i]+1)-(n-que[i]),query(0,que[i],n+1)-que[i]);
		//cout << query(1,0,que[i]+1)-que[i]+1<< ' ' << query(0,que[i],n+1)-que[i] << endl;
		update(0,que[i-1],mi-tmp+que[i-1]);
		update(1,que[i-1],mi-tmp+n-que[i-1]);
	}
	

	
	ll ans = INM;
	
	REP(i,n+1)
	{
		ans = min(ans,dp[0][i+N-1]-i);
		ans = min(ans,dp[1][i+N-1]-(n-i));
	}
	
	cout << ans + sum << endl;

	return 0;
}