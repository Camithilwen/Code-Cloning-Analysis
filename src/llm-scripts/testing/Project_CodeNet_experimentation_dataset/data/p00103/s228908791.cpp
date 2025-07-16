#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>

using namespace std;
typedef long long int LL;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int xcomp(vector<LL>& a, vector<LL>& b) {
	return a[0] < b[0];
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

#define ALL(x) (x).begin(),(x).end()
LL mod = 1000000007;

int main() {
	int N;
	cin >> N;
	REP(i, N) {
		int a1 = 0;
		int a2 = 0;
		int a3 = 0;
		int out = 0;
		int pt = 0;
		while (true) {

			string s;
			cin >> s;
			if (s[1] == 'I') {
				if (a3 == 1) {
					a3 = 0;
					pt++;
				}
				if (a2 == 1) {
					a2 = 0;
					a3 = 1;
				}
				if (a1 == 1) {
					a1 = 0;
					a2 = 1;
				}
				a1 = 1;
			}
			else
				if (s[1] == 'U') {
					out++;
					if (out == 3) {
						break;
					}
				}
				else {
					if (a1 == 1) {
						a1 = 0;
						pt++;
					}
					if (a2 == 1) {
						a2 = 0;
						pt++;
					}
					if (a3 == 1) {
						a3 = 0;
						pt++;
					}
					pt++;
				}
		}
		cout << pt << endl;
	}
}