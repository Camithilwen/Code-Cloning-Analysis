#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#define _GLIBCXX_DEBUG

#include <iomanip>
using namespace std;

template<typename T> vector<T> range(T begin, T end, T stride = 1) {
    vector<T> vec;
    for (T i = begin; i < end; i += stride) {
        vec.push_back(i);
    }
    return vec;
}

template<typename T> T factorial(T in) {
    long long ans = 1;
    for (int i=2; i < in + 1; ++i) ans *= i;
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> v = range(0, n);
    vector<int> x(n), y(n);
    for (int i=0; i < n; ++i) cin >> x[i] >> y[i];
    double sum = 0;
    do {
        for (int i=0; i<n-1; i++) {
            sum += sqrt((x[v[i+1]] - x[v[i]]) * (x[v[i+1]] - x[v[i]]) + (y[v[i+1]] - y[v[i]]) * (y[v[i+1]] - y[v[i]]));
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << fixed << setprecision(15) << sum / factorial(n) << endl;
}
