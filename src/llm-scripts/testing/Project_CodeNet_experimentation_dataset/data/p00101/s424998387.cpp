#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <numeric>
#include <sstream>

#define REP(i, n) for(int i = 0;i < (n); i++)
#define REP2(i, x, n) for(int i = (x); i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1;i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

#define LL long long int
#define LD long double

#define PI 3.14159265358979

using namespace std;

//================================================

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	cin.ignore();

	string from = "Hoshino";
	REP(i, N) {
		string S;
		getline(cin, S);

		while(true) { 
			int res = S.find("Hoshino", 0);
			if (res == -1) break;

			S.replace(res, 7, "Hoshina");
		}
		cout << S << "\n";
	}
	return 0;
}