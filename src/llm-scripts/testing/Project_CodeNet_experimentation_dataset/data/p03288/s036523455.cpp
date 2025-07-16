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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int r;
    cin >> r;
    if (r < 1200) {
        cout << "ABC" << endl;
    }
    else if (r < 2800) {
        cout << "ARC" << endl;
    }
    else {
        cout << "AGC" << endl;
    }
    return 0;
}
