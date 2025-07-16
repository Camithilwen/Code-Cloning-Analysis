#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	while ( cin >> N ) {
		if ( N == 0 ) {		 
			break;
		}
		typedef pair<double, string> P;
		vector<P> ans;
		while ( N-- ) {
			string l;
			int p;
			cin >> l >> p;
			int t = 0;
			int d = 0;
			for ( int i = 0; i < 5; i++ ) {
				int a;
				cin >> a;
				if ( i <= 2 ) t += a;
				else d += a;
			}
			int f, s, m;
			int sum = 0;
			cin >> f >> s >> m;

			t += d*m;
			sum = f*s*m;
			ans.push_back(P(-((double)(sum-p)/(double)t), l));
		}
		sort(ans.begin(), ans.end());

		for ( int i = 0; i < ans.size(); i++ ) {
			cout << ans[i].second << endl;
		}
		cout << '#' << endl;
	}
	return 0;
}
	

