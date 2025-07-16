#include <cstdio>
using namespace std;

int n;
int m;
int maxcnt;
int maxidx;
int a[1000];
int cnt[1000];

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i=0; i<m; i++) {
        int b;

        scanf("%d", &b);
        for (int i=0; i<n; i++) {
            if (a[i] <= b) {
                cnt[i]++;
                if (maxcnt < cnt[i]) {
                    maxcnt = cnt[i];
                    maxidx = i;
                }
                break;
            }
        }
    }

    printf("%d\n", maxidx+1);
}