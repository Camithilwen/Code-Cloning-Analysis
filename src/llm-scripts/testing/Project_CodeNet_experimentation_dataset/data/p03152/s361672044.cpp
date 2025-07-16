#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

long long M = 1e9 + 7;
int a[N], b[N], n, m;
long long res = 1;
long long mrk[N * N];
vector <pair <int, int> > v;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	for (int i = 0; i < n; i++)
		for (int ii = i + 1; ii < n; ii++)
			if (a[ii] == a[i]) {
				cout << "0";
				return 0;
			}
	for (int j = 0; j < m; j++)
		for (int jj = j + 1; jj < m; jj++)
			if (b[jj] == b[j]) {
				cout << 0;
				return 0;
			}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (a[i] == b[j])
				mrk[a[i]] = 1;
	for (int i = 0; i < n; i++) {
		if (mrk[a[i]])
			continue;
		for (int j = 0; j < m; j++)
			if (b[j] > a[i])
				mrk[a[i]]++;
	}
	for (int j = 0; j < m; j++) {
		if (mrk[b[j]])
			continue;
		for (int i = 0; i < n; i++)
			if (a[i] > b[j])
				mrk[b[j]]++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v.push_back({i, j});
	sort(v.begin(), v.end(), [](pair <int, int> x, pair <int, int> y) {
		return min(a[x.first], b[x.second]) < min(a[y.first], b[y.second]);		
	});/*
	for (int i = 0; i < v.size(); i++)
		cout << i << " v[i] " << v[i].first << " " << v[i].second << endl;
*/	for (int pnt = n * m; pnt >= 1; pnt--) {
		if (mrk[pnt]) {
			res *= mrk[pnt];
			res %= M;
//			cout << pnt << " RES :::::" << res << " " << mrk[pnt] << endl;
			continue;	
		}
		int l = -1, r = v.size(), md;
		while (r - l > 1) {
			md = (r + l) / 2;
			if (min(a[v[md].first], b[v[md].second]) > pnt)
				r = md;
			else
				l = md;
		}
		res *= (v.size() - r - (n * m - pnt));
		res %= M;
//		cout << pnt << " RES " << res << " R " << r << " " << (v.size() - r - (n * m - pnt)) << endl;
	}
	cout << res;
	return 0;
}






































