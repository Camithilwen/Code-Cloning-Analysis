#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define rep(i,n) for(int i = 0; i < n; i++)
#define MSG(a) cout << #a << " " << a << endl;
template<class T, class C> pair<T,C> mp(T a, C b){ return make_pair(a, b);}

int main()
{
	int n;
	while(cin >> n && n)
	{
		vector<vector<bool> > s(n, vector<bool>(n));
		rep(i,n+1) fill(s[0].begin(), s[0].end(), false);

		int m;
		cin >> m;

		rep(i,m)
		{
			int a, b;
			cin >> a >> b;
			s[a-1][b-1] = s[b-1][a-1] = true;
		}

		int res = 0;

		for(int i = 1; i < n; i++)
		{
			if(s[0][i])	res++;
			else
			{
				for(int j = 1; j < n; j++)
				{
					if(s[0][j] && s[j][i])
					{
						res++;
						break;
					}
				}
			}
		}
		cout << res << endl;
	}
}