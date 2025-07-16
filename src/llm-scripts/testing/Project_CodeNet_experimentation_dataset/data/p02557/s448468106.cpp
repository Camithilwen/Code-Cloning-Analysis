#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 200010;
int n, a[N], b[N], cnt, tot;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[n - i + 1];
    int l = 1, r = n, st = 0, ed = -1;
    for (int i = 1; i <= n; i++)
        if (a[i] == b[i]) {
            if (!st) st = i;
            ed = i;
        }
    for (int j = st; j <= ed; j++) {
        if (a[l] ^ b[j] && b[l] ^ b[j]) swap(b[j], b[l++]);
        else if (a[r] ^ b[j] && b[r] ^ b[j]) swap(b[j], b[r--]);
        else puts("No"), exit(0);
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
    return 0;
}
