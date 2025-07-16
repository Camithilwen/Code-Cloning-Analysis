#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull B = 100000007;
ll mod = 1000000007;
int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);

    int u1 = 1+m;
    int d1 = 1;
    int u2=  n;
    int d2 = n - m + 1;

    int c = 0;

    while (u1 > d1 && c < m) {
        cout << u1 << " " << d1 << endl;
        d1++; u1--;
        c++;
    }
    while (u2 > d2 && c < m) {
        cout << u2 << " " << d2 << endl;
        d2++; u2--;
        c++;
    }
}

