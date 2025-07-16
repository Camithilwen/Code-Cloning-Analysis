#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 2e5 + 100;
int T;

int n, k, a[N];

bool work() {
    static int s[N];
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
        int l = max(1, i - a[i]), r = min(n, i + a[i]);
        s[l]++, s[r + 1]--;
    }
    bool res = false;
    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        if (s[i] != a[i]) {
            res = true;
            a[i] = s[i];
        }
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= k; i++)
        if (!work()) break;
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}