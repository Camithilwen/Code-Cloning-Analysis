#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	int n, tmp;
	cin >> n;
	map<int, int> odd, even;
	rep(i, n) {
		cin >> tmp;
		if (i % 2 == 0)	even[tmp]++;
		else odd[tmp]++;
	}
	P oddMax, evenMax;
	oddMax = make_pair(-1, -1);
	evenMax = make_pair(-1, -1);
	int oddOthers, evenOthers;
	oddOthers = evenOthers = 0;
	for (auto a : odd) {
		if (oddMax.second < a.second)	oddMax = a;
	}
	for (auto a : even) {
		if (evenMax.second < a.second)	evenMax = a;
	}

	int ans = iINF;
	if (oddMax.first == evenMax.first) {
		int tmpAns = 0;
		int tmpOdd, tmpEven;
		tmpOdd = tmpEven = 0;
		for (auto a : odd) {
			if (a.first == oddMax.first) continue;
			tmpOdd += a.second;
		}
		for (auto a : even) {
			if (a.first == evenMax.first) continue;
			tmpEven += a.second;
		}


		tmpAns = tmpOdd;
		P tmpEvenMax = make_pair(-1, -1);
		for (auto a : even) {
			if (a.first == evenMax.first) continue;
			if (tmpEvenMax.second < a.second)	tmpEvenMax = a;
		}
		int tmptmpEven = 0;
		for (auto a : even) {
			if (a.first == tmpEvenMax.first) continue;
			tmptmpEven += a.second;
		}
		tmpAns += tmptmpEven;
		ans = min(ans, tmpAns);

		tmpAns = tmpEven;
		P tmpOddMax = make_pair(-1, -1);
		for (auto a : odd) {
			if (a.first == oddMax.first) continue;
			if (tmpOddMax.second < a.second)	tmpOddMax = a;
		}
		int tmptmpOdd = 0;
		for (auto a : odd) {
			if (a.first == tmpOddMax.first) continue;
			tmptmpOdd += a.second;
		}
		tmpAns += tmptmpOdd;
		ans = min(ans, tmpAns);
	}
	else {
		ans = 0;
		for (auto a : odd) {
			if (a.first == oddMax.first) continue;
			ans += a.second;
		}
		for (auto a : even) {
			if (a.first == evenMax.first) continue;
			ans += a.second;
		}
	}
	cout << ans << endl;
	return 0;
}