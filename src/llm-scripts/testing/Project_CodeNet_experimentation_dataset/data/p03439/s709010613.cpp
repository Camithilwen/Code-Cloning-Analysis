#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int anser(string s) {
	if (s == "Male") {
		return 0;
	}
	if (s == "Female") {
		return 1;
	}
	if (s == "Vacant") {
		exit(0);
	}
	exit(-1);
}

int query(int p) {
	cout << p << endl;
	string s;
	cin >> s;
	return anser(s);

}



bool bingo(int d, int v1, int v2) {
	if (d % 2 == 0) {
		return v1 != v2;
	} else {
		return v1 == v2;
	}
}

int main() {
	int n;
	cin >> n;
	int from = 0;
	int to = n - 1;

	int from_q = query(from);
	int to_q = query(to);

	while(true) {
		int mid = from + (to - from) / 2;
		int mid_q = query(mid);

		if (bingo(mid - from,from_q, mid_q)) {
			to = mid;
			to_q = mid_q;
		} else if (bingo(to - mid, mid_q, to_q)) {
			from = mid;
			from_q = mid_q;
		} else {
			int a[0];
			a[-10000000] = 0;
		}
	}

	return 0;
}