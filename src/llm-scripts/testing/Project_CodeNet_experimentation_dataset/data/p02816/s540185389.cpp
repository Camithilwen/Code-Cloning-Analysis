#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> suffix_array(vector<int>& s) {
    int n = s.size();
    vector<int> p(n), c(n), cnt(n);
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < n; i++) cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    int cl = 0;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]]) cl++;
        c[p[i]] = cl;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < n; i++) cnt[i] += cnt[i-1];
        for (int i = n - 1; i >= 0; i--) {
            cnt[c[pn[i]]]--;
            p[cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        cl = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur(c[p[i]], c[(p[i] + (1 << h)) % n]);
            pair<int, int> prev(c[p[i-1]], c[(p[i-1] + (1 << h)) % n]);
            if (cur != prev) cl++;
            cn[p[i]] = cl;
        }
        swap(c, cn);
    }
    return p;
}

int bin_search(vector<int>& a, vector<int>& b, vector<int>& sa, bool lower) {
    int n = a.size();
    int lb = -1, ub = n;
    while (ub - lb > 1) {
        int m = (lb + ub) / 2;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            int j = (sa[m] + i) % n;
            if (a[i] < b[j]) {
                ub = m;
                flag = true;
                break;
            }
            if (a[i] > b[j]) {
                lb = m;
                flag = true;
                break;
            }
        }
        if (!flag) {
            if (lower) ub = m;
            else lb = m;
        }
    }
    return ub;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    vector<int> cnt(N);
    for (int i = 0; i < 30; i++) {
        vector<int> c(N), d(N);
        for (int j = 0; j < N; j++) {
            c[j] = a[j] >> i & 1;
            d[j] = b[j] >> i & 1;
        }
        auto sa = suffix_array(d);
        int lb = bin_search(c, d, sa, true);
        int ub = bin_search(c, d, sa, false);
        for (int j = lb; j < ub; j++) cnt[(N - sa[j]) % N]++;

        for (int j = 0; j < N; j++) c[j] = 1 - c[j];
        lb = bin_search(c, d, sa, true);
        ub = bin_search(c, d, sa, false);
        for (int j = lb; j < ub; j++) cnt[(N - sa[j]) % N]++;
    }
    for (int k = 0; k < N; k++) {
        if (cnt[k] == 30) {
            int x = a[k] ^ b[0];
            cout << k << " " << x << "\n";
        }
    }
}