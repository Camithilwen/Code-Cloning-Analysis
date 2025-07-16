#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int gcd(int a, int b) {
    if(a < b) {
        swap(a, b);
    }
    if(b < 1)
        return -1;
    if(a % b == 0)
        return b; 
    return gcd(b, a % b);
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N)
        cin >> A[i];

    if(A.size() == 1) {
        if(A[0] != K) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
        }
        return 0;
    }

    sort(A.begin(), A.end());
    if(A.back() < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int gcd_val = A[0];
    for(int i=1; i<N; ++i) {
        gcd_val = gcd(gcd_val, A[i]);
    }

    rep(i, N) {
        if(A[i] == K) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
        if(A[i] < K) {
            continue;
        }
        A[i] -= K;

        if( A[i] % gcd_val == 0) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
        cout << "IMPOSSIBLE" << endl;

    return 0;
}

