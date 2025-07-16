#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	int n, m;
	cin >> n >> m;
	vector <vector <int>> a(n, vector <int> (m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	int g = 1e9;
	vector <bool> done(m, false);
	int iter = 0;
	while(iter < m) {
		vector <int> cnt(m, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(!done[a[i][j]]) {
					cnt[a[i][j]]++;
					break;
				}
			}
		}
		int el = max_element(all(cnt)) - cnt.begin();
		g = min(g, cnt[el]);
		done[el] = true;
		iter++;
	}
	cout << g << endl;

    return 0;
}