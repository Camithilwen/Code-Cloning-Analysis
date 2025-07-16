#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define popcount __builtin_popcount

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };



int roman_to_n(const string& s)
{
	static const int num[] = { 1, 5, 10, 50, 100, 500, 1000 };
	static const char* roman = "IVXLCDM";

	vector<int> digits(s.size());
	for (int i = 0; i < s.size(); ++i)
		digits[i] = num[strchr(roman, s[i]) - roman];

	int res = accumulate(digits.begin(), digits.end(), 0);
	for (int i = 0; i < digits.size() - 1; ++i)
		if (digits[i] < digits[i + 1])
			res -= 2 * digits[i];
	return res;
}
string to_roman(int n)
{
	static const char* roman[][10] = {
		{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, 
		{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		{ "", "M", "MM", "MMM", "MMMM", "MMMMM" },
	};

	stringstream res;
	for (int i = 3, j = 1000; i >= 0; --i, j /= 10)
		res << roman[i][(n / j) % 10];
	return res.str();
}
int main()
{
	string s;
	while (cin >> s)
		cout << roman_to_n(s) << endl;
}