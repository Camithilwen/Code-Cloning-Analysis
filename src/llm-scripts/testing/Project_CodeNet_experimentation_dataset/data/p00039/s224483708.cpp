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



int main()
{
	string str;
	map<char, int> p;

	p.insert(map<char, int>::value_type('I', 1));
	p.insert(map<char, int>::value_type('V', 5));
	p.insert(map<char, int>::value_type('X', 10));
	p.insert(map<char, int>::value_type('L', 50));
	p.insert(map<char, int>::value_type('C', 100));
	p.insert(map<char, int>::value_type('D', 500));
	p.insert(map<char, int>::value_type('M', 1000));


	while(cin >> str)
	{
		int len = str.size();
		vint num(len);

		rep(i, len)
			num[i] = p[str[i]];

		int res = num[len-1];
		rep(i, len-1)
		{
			if(num[i+1] <= num[i])
			{
				res += num[i];
			}
			else
			{
				res -= num[i];
				if(i + 1 != len - 1) res += num[i+1];
				i++;
			}
		}

		cout << res << endl;
	}
}