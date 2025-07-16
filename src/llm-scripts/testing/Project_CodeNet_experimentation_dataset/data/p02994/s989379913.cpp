#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int n, l;
    cin >> n >> l;

    int r = n + l - 1;

    int eat;

    if (r <= 0) eat = r;
    else if (l >= 0) eat = l;
    else eat = 0;

    cout << (r + l) * (r- l + 1) / 2 - eat << endl;

    return 0;
}