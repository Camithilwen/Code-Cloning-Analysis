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

int main() {
    int K, T;
    cin >> K >>T;
    vector<int> A(T);
    rep(i, T)
        cin >> A[i];

    if(T==1) {
        cout << K-1 << endl;
        return 0;
    }

    sort(A.rbegin(), A.rend());
    int64_t ret = A[0];
    int64_t sum = 0;
    rep(i, A.size()-1) {
        sum += A[i+1];
    }
    if(ret-sum-1 <= 0) {
        ret = 0;
    } else {
        ret = ret-sum-1;
    }
    cout << ret << endl;
    return 0;
}

