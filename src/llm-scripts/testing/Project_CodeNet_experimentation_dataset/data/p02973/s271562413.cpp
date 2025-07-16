#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;

char s[100005];
long long dp[100005][13];

int minimum_Color(vector<int> a, int n) {
    multiset<int> last;

    for (int i = 0; i < n; i++) {
        auto it = last.lower_bound(a[i]);
        if (it == last.begin()) {
            last.insert(a[i]);
        }
        else {
            it--;
            last.erase(it);
            last.insert(a[i]);
        }
    }
    return last.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    cout << minimum_Color(a, n);
    return 0;
}