#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int ch[100000];
deque<int> pr;
llong P1[500];
llong P2[500];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 2; i < 100000; ++i) {
        if (ch[i]) continue;
        pr.push_back(i);
        for (llong j = (llong)i * i; j < 100000; j += i) ch[j] = 1;
	}
        
	int n;
	cin >> n;
	if (n == 2) {
        printf("4 7\n23 10\n");
        return 0;
	}
	for (int i = 0; i <= ((n + n - 2) >> 1); ++i) {
        P1[i] = pr.front();
        pr.pop_front();
	}
	for (int i = 0; i <= ((n + n - 2) >> 1); ++i) {
        P2[i] = pr.front();
        pr.pop_front();
	}
	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) & 1) {
                int x = (i + j), y = (i - j + (n - 1));
                llong ret = 1;
                if (x > 0) ret *= P1[x - 1 >> 1];
                if (x + 1 <= n + n - 2) ret *= P1[x + 1 >> 1];
                if (y > 0) ret *= P2[y - 1 >> 1];
                if (y + 1 <= n + n - 2) ret *= P2[y + 1 >> 1];
                printf("%lld", ret + 1);
                //if (ret > 1e15) { printf("%lld\n", ret); }
            }
            else {
                printf("%lld", P1[i + j >> 1] * P2[i - j + (n - 1) >> 1]);
            }
            if (j + 1 < n) printf(" ");
            else printf("\n");
        }
	}
	return 0;
}
