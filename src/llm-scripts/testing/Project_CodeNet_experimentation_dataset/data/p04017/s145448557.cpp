/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.21 02:11:21
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    n++;
    int l;cin >> l;
    x.push_back(x[x.size()-1] + l);
    vector<int> next(n);
    for (int i = 0; i < n; i++) {
        auto t = upper_bound(x.begin(), x.end(), x[i] + l);
        t--;
        next[i] = t - x.begin();
    }
    vector<vector<int>> doubling(32,vector<int>(n));
    for (int i = 0; i < n; i++) {
        doubling[0][i] = next[i];
    }
    for (int i = 1; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            doubling[i][j] = doubling[i-1][doubling[i-1][j]];
        }
    }
    
    int q;cin >> q;
    while(q--) {
        int a,b;cin >> a >> b;
        a--;b--;
        if (b < a) swap(a,b);
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (doubling[i][a] <= b) {
                a = doubling[i][a];
                ans += (1 << i);
            } 
        }
        if (a != b) ans++; 
        cout << ans << endl;
    }
    return 0;
}