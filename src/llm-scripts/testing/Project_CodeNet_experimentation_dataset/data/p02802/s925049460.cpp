#include <bits/stdc++.h>
 
using namespace std;

int cnt[100005];
bool ac[100005];
 
char s[5];
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
 
    int pen = 0;
    int res = 0;
 
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d%s", &x, s);
 
        if (s[0] == 'A') {
            if (!ac[x]) {
                res++;
                pen += cnt[x];
            }
            ac[x] = 1;
        }
        else {
            cnt[x]++;
        }
    }
 
    printf("%d %d\n", res, pen);
}
