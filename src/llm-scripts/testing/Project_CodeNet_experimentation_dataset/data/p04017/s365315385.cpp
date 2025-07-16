#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <iomanip>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) os << *i << (i == end(v) - 1 ? "" : " "); return os;
}
template<class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) is >> *i; return is;
}

#define MOD 1000000007

struct Q {
	int b_id;
	int steps;
	int q_id;

	Q(int b_id, int q_id) : b_id(b_id), q_id(q_id), steps(0) {}

	bool operator<(const Q& other) const
	{
		return std::tie(b_id, q_id) < std::tie(other.b_id, other.q_id);
	}
};

int ofs[1000000];
int ans[1000000];
vector<set<Q>> qs;

void merge_into(int from, int to)
{
	if (qs[from].size() > qs[to].size())
	{
		swap(qs[from], qs[to]);
		swap(ofs[from], ofs[to]);
	}
	for (auto x : qs[from])
	{
		x.steps += ofs[from] - ofs[to];
		qs[to].insert(x);
	}
	qs[from].clear();
}

int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	qs.resize(n);

	int L;
	cin >> L;

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;

		if (a > b)
			swap(a, b);
		qs[a].insert(Q(b, i));
	}

	for (int i = 0; i < n; i++)
	{
		while (qs[i].size() > 0 && qs[i].begin()->b_id <= i)
		{
			auto f = *qs[i].begin();
			qs[i].erase(qs[i].begin());
			ans[f.q_id] = f.steps + ofs[i];
		}
		ofs[i]++;
		int to = lower_bound(x.begin(), x.end(), x[i] + L + 1) - x.begin() - 1;
		merge_into(i, to);
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";

	return 0;
}
