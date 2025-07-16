#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<climits>
#include<stack>
#include<queue>
#include<cmath>
#define int long long
#define INF 100000000000
#define EPS 0.0000000001

using namespace std;

signed main() {
	int n, m;
	int a[1010], b[1010];
	int ans[1010] = { 0 };
	int vote = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] <= b[i]) {
				ans[j]++;
				//cout << j + 1 << endl;
				break;
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		//for (int j = 0; j < n; j++) {
			//cout << ans[i] << " " << endl;
			if (temp < ans[i]) {
				//cout << "[" << i << "]" << endl;
				temp = ans[i];
				vote = i;
			}
		//}
	}
	cout << vote + 1 << endl;
	return 0;
}