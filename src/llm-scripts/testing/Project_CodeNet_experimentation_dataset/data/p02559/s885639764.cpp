#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <atcoder/all>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace atcoder;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 3000000;
const int K = 100000;
const int mod = 1e9 + 7;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    cin >> n >> q;
    fenwick_tree<int> f(n);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        f.add(i, x);
    }
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0){
            f.add(l, r);
        } else{
            cout << f.sum(l, r) << endl;
        }
    }
}
