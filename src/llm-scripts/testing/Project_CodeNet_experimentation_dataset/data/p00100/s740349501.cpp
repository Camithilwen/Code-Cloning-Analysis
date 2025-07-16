#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n-1)

const double EPS = 1e-10;
const double PI = acos(-1.0);

int main() {
	ll n;
	map<int, ll> field;
	vi jun;

	while(cin >> n, n) {
		field.clear();
		jun.clear();

		int ban;
		ll tan, suu;
		bool flag = true;

		REP(i, n) {
			cin >> ban >> tan >> suu;

			if(!field[ban]) {
				jun.push_back(ban);
			}

			if(field[ban] < 1000000) {
				field[ban] += tan*suu;
			}
		}

		if(jun.size() == 0) {
			cout << "NA" << endl;
		} else {
			REP(i, jun.size()) {
				if(field[jun[i]] >= 1000000) {
					cout << jun[i] << endl;
					flag = false;
				}
			}
			if(flag) {
				cout << "NA" << endl;
			}
		}
	}

	return 0;
}