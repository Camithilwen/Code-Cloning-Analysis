#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define rp(i,c) rep(i,(c).size())
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf=1<<28;
const double INF=1e12,EPS=1e-9;

int n,k,card[10],digit[10];
bool use[10];
set<ll> S;

void rec(ll num,int depth)
{
	if(depth==0)
	{
		S.insert(num); return;
	}
	rep(i,n)if(!use[i])
	{
		use[i]=1;
		rec(num*digit[i]+card[i],depth-1);
		use[i]=0;
	}
}

int main()
{
	while(cin>>n>>k,n)
	{
		rep(i,n)
		{
			cin>>card[i];
			digit[i]=card[i]>9?100:10;
		}
		fill_n(use,n,0); S.clear();
		rec(0,k);
		cout<<S.size()<<endl;
	}
	return 0;
}