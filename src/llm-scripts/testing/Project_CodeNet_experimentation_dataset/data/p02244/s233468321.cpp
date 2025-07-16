#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iomanip>
#include<complex>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<map>
#include<set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef stack<int> SI;
typedef queue<int> QI;
typedef list<int> LI;
typedef pair<int,int> PII;
typedef long long LL;

#define d(x)  cout<<#x<<" = "<<(x)<<endl;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define EMP empty()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define REACH(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c,n) sort(c,c+n)
#define VSORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define DFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define DREP(i,n) DFOR(i,n,0)
#define INF 1000000000
#define PI  acos(-1.0)
////////////////////////////////////////////////
#define N 8
int row[N],col[N],dpos[N*2-1],dneg[N*2-1];
bool X[N][N];

void print()
{
	REP(i,N)
	{
		REP(j,N)
		{
			if(X[i][j])
			{
				if(row[i]!=j)return ;
			}
		}
	}
	REP(i,N)
	{
		REP(j,N)
		{
			cout<<((row[i]==j)?"Q":".");
		}
		cout<<endl;
	}
}

void recursive(int i)
{
	if(i==N)
	{
		print();
		return;
	}
	
	REP(j,N)
	{
		if(col[j]+dpos[i+j]+dneg[i-j+N-1]!=0)continue;
		row[i]=j;col[j]|=1;dpos[i+j]|=1;dneg[i-j+N-1]|=1;
		recursive(i+1);
		row[i]^=row[i];col[j]^=col[j];dpos[i+j]^=dpos[i+j];dneg[i-j+N-1]^=dneg[i-j+N-1];
	}
}
int main()
{
	int k;
	scanf("%d",&k);
	REP(i,k)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		X[r][c]=true;
	}
	recursive(0);
	return 0;
}