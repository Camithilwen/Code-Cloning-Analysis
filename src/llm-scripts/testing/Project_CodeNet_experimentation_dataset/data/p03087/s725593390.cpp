#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>

// ===============================================================

using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;

// ===============================================================

ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}
//最大公約数
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
//最小公倍数
ll box(double a) 
{
	ll b = a;
	return b;
}
//切り捨て
ll fff(double a) 
{
	ll b = a + 0.5;
	return b;
}
//四捨五入
ll sum(ll n) { 
	return (1 + n) * n / 2;
}
//1から整数nまでの合計
bool prime(ll a)//素数判定、primeならtrue,違うならfalse
{
	if (a < 2) return false;
	else if (a == 2) return true;
	else if (a % 2 == 0) return false;
	double sqrtNum = sqrt(a);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (a % i == 0)
		{
			return false;
		}
	}

	// 素数である
	return true;
}
//素数判定

// ===============================================================

int main() {
	ll n; cin >> n;
	ll q; cin >> q;
	string a;
	cin >> a;
	vl x(q);
	vl y(q);
	for (int i = 0; i < q; i++) {
		cin >> x[i] >> y[i];
	}
	vector<ll> dataa(n);
	vector<ll> datab(n);
	ll count = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a.substr(i, 2) == "AC") {
			count++;
			dataa[i] = count;
			datab[i + 1] = count;
		}
		else {
			dataa[i] = datab[i + 1] = count;
		}
	}
	for (int i = 0; i < q; i++) {
		cout << datab[y[i] - 1] - datab[x[i] - 1] << endl;
	}
}