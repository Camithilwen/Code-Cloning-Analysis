#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int a[maxn];
int n, m;
int f[maxn], cnt = 0;
bool cmp(int a, int b) {
	return (a % 2) > (b % 2);
}
int pl;
void push(int a) {
	if (pl + a - 1 >= n) a = n + 1 - pl;
	f[cnt++] = a, pl += a;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	sort(a, a + m, cmp);
	int ans = 0;
	for (int i = 0; i < m; i++)
		ans += a[i] % 2;
	if (n % 2 == 0 && ans > 2) cout << "Impossible" << endl;
	else if (n % 2 == 1 && ans > 1) cout << "Impossible" << endl;
	else {
		pl = 1;
		if (a[1] % 2) swap(a[1], a[m - 1]);
		for (int i = 0; i < m; i++) {
			if (a[i] % 2) {
				if (i == 0) 
					for (int j = 0; j < a[i] / 2 + 1; j++)
						push(2);
				else for (int j = 0; j < a[i] / 2; j++)
					push(2);
			}
			else {
				if (i == 0) push(1);
				push(a[i]);
			}
		}
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << endl;
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++)
			printf("%d ", f[i]);
		printf("\n");
	}
	return 0;
}
