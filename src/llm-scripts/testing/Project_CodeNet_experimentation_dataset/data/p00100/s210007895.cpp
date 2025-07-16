#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define EQ(a,b) (abs((a)-(b))<EPS)
int main()
{
	ll u[4010];
	bool flag;
	vector<int> v;
	while(1)
	{
		for(int i=0;i<4010;i++)
		{
			u[i]=0;
		}
		flag=true;
		int n;
		cin >> n;
		if(n==0)break;
		v.clear();
		for(int i=0;i<n;i++)
		{
			int x;
			ll y,z;
			cin >> x >> y >> z;
			if(!(u[x]))
			{
				v.pb(x);
			}
			u[x]+=y*z;
		}
		for(int i=0;i<v.size();i++)
		{
			if(u[v[i]]>=1000000)
			{
				flag=false;
				cout << v[i] << endl;
			}
		}
		if(flag)
		{
			cout << "NA" << endl;
		}
	}
	return 0;
}