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
const int N = 1e6 + 100;
int T;
int a, b, m;
int aa[N], bb[N];
pair<pii, int> c[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> m;
    for (int i = 1; i <= a; i++)cin >> aa[i];
    for (int i = 1; i <= b; i++)cin >> bb[i];
    for (int i = 1; i <= m; i++)cin >> c[i].first.first >> c[i].first.second >> c[i].second;
    int ans = *min_element(aa + 1, aa + a + 1) + *min_element(bb + 1, bb + b + 1);
    for (int i = 1; i <= m; i++) {
        ans = min(ans, aa[c[i].first.first] + bb[c[i].first.second] - c[i].second);
    }
    cout << ans << endl;
    return 0;
}