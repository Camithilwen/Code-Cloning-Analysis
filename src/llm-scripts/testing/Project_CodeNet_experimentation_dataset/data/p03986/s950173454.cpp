#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	string x; cin >> x;
	int n = x.size();
	vector<char> st;
	REP(i, n) {
		if (x[i] == 'S')
			st.push_back('S');
		else {
			if (st.empty())
				st.push_back('T');
			else if (st.back() == 'S')
				st.pop_back();
			else if (st.back() == 'T')
				st.push_back('T');
		}
	}
	cout << st.size() << '\n';
	return 0;
}
