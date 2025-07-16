#include <bits/stdc++.h>
 
#define pp push_back
#define pf push_front
#define mp make_pair
#define fs first
#define sc second
#define sf scanf
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
 
const int N = (int) 1e6;
const int INF = (int) 1e9 + 7;
 
bool comp(ii a, ii b) {
	int x = max(a.fs, a.sc) - a.sc;
	int y = max(b.fs, b.sc) - b.sc;
	return x > y;
}
 
int main(int argc, char *argv[])
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
 
	int n;
	sf("%d", &n);
	char s[N + 7];
	int l = 0, r = 0;
	vector<ii> a;
	vector<ii> b;
	for (int j = 0; j < n; ++j) {
		sf("%s", s);
		int x = 0;
		int y = 0;
		for (int i = 0; i < strlen(s); ++i) {
			if (s[i] == '(') {
				++x;
			}
			else {
				if (x < 1) {
					++y;
				}
				else {
					--x;
				}
			}
		}
 
		if (x > 0 && y > 0) {
			if (x > y) {
				a.pp(mp(y, x));
			}
			else {
				b.pp(mp(y, x));
			}
		}
		else {
			l += x;
			r += y;
		}
	}
 
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i) {
		if (l < a[i].fs) {
			puts("No");
			return 0;
		}
 
		l += a[i].sc - a[i].fs;
 
		if (l < 0) {
			puts("No");
			return 0;
		}
	}

	sort(b.begin(), b.end(), greater<ii>());
	for (int i = 0; i < b.size(); ++i) {
		if (l < b[i].fs) {
			puts("No");
			return 0;
		}

		l += b[i].sc - b[i].fs;
 
		if (l < 0) {
			puts("No");
			return 0;
		}
	}
 
	puts(l == r ? "Yes" : "No");
 
	return 0;
}
