#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	long long int m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		long long int b;
		vector<long long int> ss;
		ss.push_back(0);
		for (int i = 0; i < n; i++) {
			cin >> b;
			if (b <= m) {
				ss.push_back(b);
			}
		}
		vector<long long int> ss2;
		for (long long int i = 0; i < ss.size(); i++) {
			ss2.push_back(ss[i]);
			for (long long int j = i; j < ss.size(); j++) {
				if (ss[i]+ss[j] <= m) {
					ss2.push_back(ss[i]+ss[j]);
				}
			}
		}
		sort(ss2.begin(), ss2.end());
		/*for (long long int i = 0; i < ss2.size(); i++) {
			cout << ss2[i] << endl;
		}*/
		long long int MAX = 0;
		long long int sz = ss2.size();
		for (long long int j = 0; j < sz; j++) {
			long long int a = m;
			for (long long int i = 0; i < 2; i++) {
				vector<long long int>::iterator ite = upper_bound(ss2.begin(), ss2.end(), a);
				if (ite != ss.begin()) {
					ite--;
					a -= *(ite);
				}
			}
			vector<long long int>::iterator ite2 = ss2.end();
			ss2.erase(ite2-1);
			MAX = max(MAX, m-a);
		}
		cout << MAX << endl;
	}
	return 0;
}