#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		auto itr = st.lower_bound(a);
		if (itr == st.begin()) {
			st.insert(a);
		} else {
			itr--;
			st.erase(itr);
			st.insert(a);
		}

	}
	int ans = st.size();
	cout << ans << endl;
	return 0;
}