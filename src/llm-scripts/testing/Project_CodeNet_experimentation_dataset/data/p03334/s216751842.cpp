#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <functional>
#include <random>

using namespace std;

const int N = 1000;

int ind[N][N];

vector<pair<int, int>> apply(vector<pair<int, int>> v, int x) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ind[i][j] = -1;
        }
    }
    vector<pair<int, int>> vecs;
    for (int i = 0; i * i <= x; i++) {
        for (int j = 0; j * j <= x; j++) {
            if (i * i + j * j == x) {
                vecs.push_back({-i, j});
                vecs.push_back({i, -j});
                vecs.push_back({i, j});
                vecs.push_back({-i, -j});
            }
        }
    } 
    int n = (int)v.size();
    for (int i = 0; i < n; i++) {
        ind[v[i].first][v[i].second] = i;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int f, s;
        tie(f, s) = v[i];
        for (auto t : vecs) {
            int dx, dy;
            tie(dx, dy) = t;
            if (f + dx > N || f + dx < 0) continue;
            if (s + dy > N || s + dy < 0) continue;
            if (ind[f + dx][s + dy] != -1) {
                g[i].push_back(ind[f + dx][s + dy]);
            }
        }
    }
    vector<int> used(n);
    vector<int> cl(n);
    vector<int> lol(2);
    function<void(int, int)> dfs = [&](int cur, int c) {
        used[cur] = 1;
        cl[cur] = c;
        lol[c]++;
        for (auto t : g[cur]) {
            if (!used[t]) {
                dfs(t, c ^ 1);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, 0);
        }
    }
    int mx = 0;
    if (lol[1] > lol[0]) mx = 1;
    vector<pair<int, int>> tk;
    for (int i = 0; i < n; i++) {
        if (cl[i] == mx) {
            tk.push_back(v[i]);
        }
    }
    return tk;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n *= 2;
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 % 2 < d2 % 2) {
        swap(d1, d2);
    }
    if (d2 % 2 == 1) {
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                cout << i << ' ' << j << endl;
            }
        }
        exit(0);
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d1 % 2) {
                if ((i + j) % 2 == 0) {
                    v.push_back({i, j});
                }
            } else {
                v.push_back({i, j});
            }
        }
    }
    if (d1 % 2 == 0) {
        v = apply(v, d1);
    }
    v = apply(v, d2);
    for (int i = 0; i < n * n / 4; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}   
