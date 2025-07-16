#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int a, b;
    cin >> a >> b;
    int d = 0;
    rep(i, b) {
        int c;
        cin >> c;
        d = max(d, c);
    }
    cout << max(0, d-(a-d)-1) << endl;

    return 0;
}