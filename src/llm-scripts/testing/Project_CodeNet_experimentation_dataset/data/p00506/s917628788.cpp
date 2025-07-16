#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
 
vector<long long int> divisor(long long int n) {
    vector<long long int> res;
    for (long long int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(begin(res), end(res));
    return res;
}
long long int gcd(long long int l, long long int r) {
    if (l > r)return gcd(r, l);
    else {
        if (r%l) {
            return gcd(l, r%l);
 
        }
        else {
            return l;
        }
    }
}
int main() {
    int N; cin >> N;
    vector<long long int>ns(N);
    for (int i = 0; i < N; ++i) {
        cin >> ns[i];
    }
    long long int a =  gcd(ns[0], ns[1]);
    if (N == 3) {
        a =  gcd(a, ns[2]);
    }
    auto v(divisor(a));
    for (auto n : v) {
        cout << n << endl;
    }
    return 0;
}
