#include <bits/stdc++.h>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)
#define INF 1000000000
#define PI 3.14159265359

typedef long long ll;
typedef pair<ll,ll> P;

int main()
{
	int n;cin >> n;
	vector<double> x(n),y(n);
	
	REP(i,n)
	{
		cin >> x[i] >> y[i];
	}
	
	REP(i,n)
	{
		vector<double> arg;
		REP(j,n)
		{
			if(i != j)
			{
				arg.PB(atan2(y[i] - y[j],x[i] - x[j]));
			}
		}
		
		sort(ALL(arg));
		
		double ma = 0;
		
		REP(j,arg.size()-1)
		{
			ma = max(ma,arg[j+1] - arg[j]);
		}
		ma = max(ma,arg[0]+2*PI - arg[arg.size()-1]);
		
		if(ma < PI)ma = 0;
		else
		{
			ma -= PI;
		}
		
		cout << Decimal << ma / (2*PI) << endl;
	}
	
	return 0;
}
