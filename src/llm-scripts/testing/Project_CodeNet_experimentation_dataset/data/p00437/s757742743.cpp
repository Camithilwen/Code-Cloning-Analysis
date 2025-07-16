#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }

bool f(int a, int b, int c)
{
	if(a == 2 && b == 1 && c == 1) return true;
	if(a == 1 && b == 2 && c == 1) return true;
	if(a == 1 && b == 1 && c == 2) return true;
	
	return false;
}

int main()
{
    for(int a, b, c; cin >> a >> b >> c && (a || b || c); )
	{
		vint S(a+b+c, 2);
		
		int N;
		cin >> N;
		
		vector<pair<pint, pint> > tests(N);
		rep(i, N)
		{
			cin >> tests[i].first.first >> tests[i].first.second;
			cin >> tests[i].second.first >> tests[i].second.second;
			
			if(tests[i].second.second == 1)
			{
				S[tests[i].first.first-1] = 1;
				S[tests[i].first.second-1] = 1;
				S[tests[i].second.first-1] = 1;
			}
		}
		
		rep(i, N)
		{
			if(f(S[tests[i].first.first-1], S[tests[i].first.second-1], S[tests[i].second.first-1]))
			{
				if(S[tests[i].first.first-1] == 2) S[tests[i].first.first-1] = 0;
				if(S[tests[i].first.second-1] == 2) S[tests[i].first.second-1] = 0;
				if(S[tests[i].second.first-1] == 2) S[tests[i].second.first-1] = 0;
			}
		}
		
		rep(i, a+b+c) cout << S[i] << endl;
	}
}