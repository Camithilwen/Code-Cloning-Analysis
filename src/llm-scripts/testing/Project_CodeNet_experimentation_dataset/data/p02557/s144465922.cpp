#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int a[200005], b[200005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; --i) {
        scanf("%d", &b[i]);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == b[i]) {
            flag = false;
            for (int j = 1; j <= n; ++j) {
                if (b[j] != a[i] && b[i] != a[j]) {
                    swap(b[j], b[i]);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
    if (flag) {
        printf("Yes\n");
        for (int i = 1; i <= n; ++i) {
            printf("%d ", b[i]);
        }
    } else {
        printf("No\n");
    }
    return 0;
}
