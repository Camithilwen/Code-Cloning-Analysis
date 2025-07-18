/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}

#define int __int64_t

int a[MAXN];

int prem[MAXN];

int n;

vector <int> mult(const vector <int>& a, const vector <int>& b) {
    vector <int> c(a.size());
    for (int i = 0; i < a.size(); i++) {
        c[i] = a[b[i]];
    }
    return c;
}

vector <int> binpow(vector <int>& a, int K) {
    int sz = a.size();
    vector <int> ans(sz);
    for (int i = 0; i < sz; i++) ans[i] = i;
    while(K) {
        if (K & 1) {
            ans = mult(ans, a);
        }
        a = mult(a, a);
        K >>= 1;
    }
    return ans;
}

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt();
    vector <int> d(n - 1);
    vector <int> perm(n - 1);
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }
    for (int i = 0; i < n - 1; i++) {
        d[i] = a[i + 1] - a[i];
        perm[i] = i;
    }

    int M = readInt(), K = readInt();
    for (int i = 1; i <= M; i++) {
        int x = readInt() - 1;
        swap(perm[x - 1], perm[x]);
    }

    vector <int> kekekek = binpow(perm, K);
    int cur = a[0];
    for (int i = 0; i < n - 1; i++) {
        cout << cur << endl;
        cur += d[kekekek[i]];
    }
    cout << cur;
    return 0;
}


