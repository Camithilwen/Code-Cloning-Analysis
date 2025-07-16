#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <bitset>
#include <random>
#include <functional>
#include <sstream>
#include <iomanip>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define rep(i, n) for(int i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define REVE(x) reverse((x).begin(),(x).end())
#define mp make_pair
#define pb push_back

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef long long LL;

int main() {
	int A, B, C, D, E; char CH;
	while (cin >> A >> CH >> B >> CH >> C >> CH >> D >> CH >> E) {
		VI a = { A,B,C,D,E };
		VI cnt(9);
		SORT(a);
		int i = 0;
		while (i < 5) {
			int elem = a[i], Cnt = 0;
			while (i < 5 && a[i] == elem) { Cnt++; i++; }
			cnt[Cnt]++;
		}

		//check
		int ans = -1;
		if (cnt[4] == 1)ans = 7;
		else if (cnt[3] == 1 && cnt[2] == 1)ans = 6;
		else {
			bool flag = false;
			if (a[0] + 1 == a[1] && a[1] + 1 == a[2] && a[2] + 1 == a[3] && a[3] + 1 == a[4])flag = true;
			else if (a[0] == 1 && a[1] == 10 && a[2] == 11 && a[3] == 12 && a[4] == 13)flag = true;
			if (flag)ans = 5;
		}

		if (ans == -1) {
			if (cnt[3] == 1)ans = 4;
			else if (cnt[2] == 2)ans = 3;
			else if (cnt[2] == 1)ans = 2;
			else ans = 1;
		}

		string str;
		switch (ans) {
		case 1:
			str = "null";
			break;
		case 2:
			str = "one pair";
			break;
		case 3:
			str = "two pair";
			break;
		case 4:
			str = "three card";
			break;
		case 5:
			str = "straight";
			break;
		case 6:
			str = "full house";
			break;
		case 7:
			str = "four card";
			break;
		}

		cout << str << endl;
	}
}
