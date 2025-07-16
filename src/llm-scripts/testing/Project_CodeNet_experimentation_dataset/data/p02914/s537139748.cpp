#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
	ll N; cin >> N;
	ll* A = new ll[N];
	ll m = 0;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum = sum ^ A[i];
		m = m | A[i];
	}

	ll filter = m - sum;

	set<ll, greater<ll>> st;
	for (int i = 0; i < N; i++) {
		ll a = A[i] & filter;
		for (auto itr = st.begin(); itr != st.end(); itr++) {
			a = min(a, a ^ *itr);
		}
		if (a != 0) {
			st.insert(a);
		}
	}

	ll s = filter;
	for (auto itr = st.begin(); itr != st.end(); itr++) {
		s = min(s, (s ^ *itr) & filter);
	}
	cout << sum + (filter - s) * 2 << endl;

	return 0;
}
