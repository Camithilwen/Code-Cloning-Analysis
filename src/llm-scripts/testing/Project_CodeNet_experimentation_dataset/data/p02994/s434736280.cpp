#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 202;
int a[N];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l;
    scanf("%d %d", &n, &l);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
		sum += l + i - 1;
	}
	int res, mn = 1e9, tot = sum;
	for (int i = 1; i <= n; i++) {
		tot -= l + i - 1;
		if (abs(tot - sum) < mn) {
			mn = abs(tot - sum);
			res = tot;
		}
		tot += l + i - 1;
	}
	printf("%d", res);
    return 0;
}
