#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >>c;

    if (a < b) {
        if (a <= c && c <= b)
            puts("Yes");
        else
            puts("No");
    }
    else {
        if (b <= c && c <= a)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}