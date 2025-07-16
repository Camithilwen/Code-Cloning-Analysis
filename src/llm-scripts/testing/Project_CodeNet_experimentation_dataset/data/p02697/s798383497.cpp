#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int l = 1, r = (n - 1) / 2;
    int ll = r + 1, rr = ll + r;
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        while (l < r && cnt < m) {
            printf("%d %d\n", l, r);
            cnt++;
            l++, r--;
        }
        l = ll, r = rr;
    }
}
