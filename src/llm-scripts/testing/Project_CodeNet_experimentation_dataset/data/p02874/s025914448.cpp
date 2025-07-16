#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}


template <typename T>
struct DisjointSparseTable{
    function<T(T, T)> f;
    vector<vector<T>> v;

    DisjointSparseTable(vector<T>& inp, function<T(T, T)> f) : f(f){
        int n = inp.size();
        int b;
        for(b = 0; (1 << b) <= inp.size(); ++b);
        v.assign(b, vector<T>(n));
        for(int i = 0; i < n; ++i)
            v[0][i] = inp[i];
        for(int i = 1; i < b; ++i){
            int siz = 1 << i;
            for(int j = 0; j < n; j += siz << 1){
                int t = min(j + siz, n);
                v[i][t - 1] = inp[t - 1];
                for(int k = t - 2; k >= j; --k)
                    v[i][k] = f(inp[k], v[i][k + 1]);
                if(t >= n)
                    break;
                v[i][t] = inp[t];
                int r = min(t + siz, n);
                for(int k = t + 1; k < r; ++k)
                    v[i][k] = f(v[i][k - 1], inp[k]);
            }
        }
    }

    T get(int l, int r){
        if(l >=r)
            return MOD;
        if(l >= --r)
            return v[0][l];
        int p = 31 - __builtin_clz(l ^ r);
        return f(v[p][l], v[p][r]);
    }
};



signed main(){

    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i];
        --l[i];
    }

    int l_ma = 0, l_ma_idx = 0;
    int r_mi = MOD, r_mi_idx = 0;
    for(int i = 0; i < n; ++i){
        if(chmax(l_ma, l[i]))
            l_ma_idx = i;
        if(chmin(r_mi, r[i]))
            r_mi_idx = i;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(i != l_ma_idx && i != r_mi_idx)
            chmax(ans, max(r_mi - l_ma, 0) + r[i] - l[i]);
    }
    if(l_ma_idx != r_mi_idx){
        vector<pair<int,int>> v;
        for(int i = 0; i < n; ++i){
            if(i != l_ma_idx && i != r_mi_idx){
                // 一定までfirstを、それ以降はsecondを見て、総和の最大化をする
                v.emplace_back(max(0, r[i] - l_ma), max(0, r_mi - l[i]));
            }
        }
        sort(v.begin(), v.end(), greater<>());
        int m = v.size();
        vector<int> v1, v2;
        for(int i = 0; i < m; ++i){
            v1.push_back(v[i].first);
            v2.push_back(v[i].second);
        }
        DisjointSparseTable<int> d1(v1, [](auto x, auto y){return min(x, y);});
        DisjointSparseTable<int> d2(v2, [](auto x, auto y){return min(x, y);});
        for(int i = 0; i <= m; ++i){
            chmax(ans, min(d1.get(0, i), r[l_ma_idx] - l[l_ma_idx]) + min(d2.get(i, m), r[r_mi_idx] - l[r_mi_idx]));
        }
    }
    cout << ans << endl;

}

