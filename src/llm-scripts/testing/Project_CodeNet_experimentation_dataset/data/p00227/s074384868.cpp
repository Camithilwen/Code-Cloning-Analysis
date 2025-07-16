#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int p[1000];
int main() {
	int n, m;
	while (cin >> n >> m, n) {
		int sum = 0;
		rep(i, n) {
			scanf("%d", &p[i]);
			sum += p[i];
		}
		sort(p, p + n, greater<>());
		for (int i = m - 1; i < n; i += m) {
			sum -= p[i];
		}
		cout << sum << endl;
	}
}