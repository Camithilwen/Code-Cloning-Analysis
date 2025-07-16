#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("fence.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    int l;
    cin >> l;

    int log = ceil(log2(n));
    vector<vector<int>> par(n, vector<int>(log + 1));
    auto build = [&]() {
        int j = n - 1;
        for (int i = n - 1; ~i; --i) {
            while (arr[j] - arr[i] > l)
                --j;
            par[i][0] = j;
        }
    };
    build();



    for (int v = n - 1; ~v; --v) {
        for (int p = 1; p <= log; ++p)
            par[v][p] = par[par[v][p - 1]][p - 1];
    }


    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u > v)
            swap(u, v);
        int ans = 0;
        for (int p = log; ~p; --p) {
            if (par[u][p] < v) {
                ans += (1 << p);
                u = par[u][p];
            }
        }
        cout << ans + 1 << '\n';
    }


    return 0;
}