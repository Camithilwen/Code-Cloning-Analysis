#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define MAX_N 10

int n, k;
vector<int> cs;
set<string> ps;

string to_s(int r) {
	ostringstream os;
	os << r;
	return os.str();
}

bool used[MAX_N];
void enumerate(int k_) {
	if (k_ == k) {
		vector<string> part;
		for (int i = 0; i < n; i++) {
			if (used[i]) {
				part.push_back(to_s(cs[i]));
			}
		}
		sort(part.begin(), part.end());
		do {
			string p = "";
			for (int i = 0; i < k; i++) p.append(part[i]);
			ps.insert(p);
		} while (next_permutation(part.begin(), part.end()));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			enumerate(k_ + 1);
			used[i] = false;
		} 
	}
}

int main() {
	while (cin >> n >> k) {
		if (n == 0 && k == 0) break;
		cs.clear();
		cs.resize(n);
		ps.clear();
		for (int i = 0; i < MAX_N; i++) used[i] = false;
		for (int i = 0; i < n; i++) cin >> cs[i];
		enumerate(0);
		cout << ps.size() << endl;
	}
	return 0;
}