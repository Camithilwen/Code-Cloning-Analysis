#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5;
int n;
char s[mxn];
int bg[mxn], ln[mxn];
int a[mxn], b[mxn];
int id[mxn];

bool comp(int x, int y) {
	return min(-a[x], -a[x] + b[x] - a[y]) > min(-a[y], -a[y] + b[y] - a[x]);
}

void NO() {
	puts("No");
	exit(0);
}

int main() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%s", s + bg[i]);
		ln[i] = strlen(s + bg[i]);
		rep(j, ln[i]) {
			if (s[bg[i] + j] == '(') {
				++ b[i];
			} else {
				if (b[i]) -- b[i];
				else ++ a[i];
			}
		}
		bg[i + 1] = bg[i] + ln[i];
		id[i] = i;
	}
	sort(id, id + n, comp);
	int A = 0;
	rep(xx, n) {
		int i = id[xx];
		A -= a[i];
		if (A < 0) NO();
		A += b[i];
	}
	if (A != 0) NO();
	puts("Yes");
	return 0;
}
