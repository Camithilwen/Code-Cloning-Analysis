
/*
g++ --std=c++17 A.cpp
*/

#include <iostream>
#include <iomanip> //! for setprecision(20)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;
using mint = static_modint<MOD>;

/*
  == AC Library Cheat sheet
  documentation: file:///Users/nobu/Downloads/ac-library/document_ja/index.html

  mint
    mint m.pow(int p)  //! return m^p
    mint m.inv() //! returns i that gives (m * i).val() == 1 
    int m.val() 

  fenwick_tree (BIT)
    fenwick_tree<T> fw(int n) //! init a[0] .. a[n-1] with all 0
    void fw.add(int idx, T x); //! a[idx] += x
    T fw.sum(int l, int r); //! return a[l] + .. + a[r-1]

  dsu (UnionFind)
    dsu d(int n)  //! prepare dsu with n nodes
    void d.merge(int x, int y)  //! connect node x and y
    bool d.same(int x, int y)  //! return true if node x and y are connected
    int d.leader(int x)  //! return the leader node of the connected group
    int d.size(int x) //! return the size of the group that node x belongs to
    vector<vector<int>> d.groups() //! return a vector of vectors that contain the nodes in each group

    
*/

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    fenwick_tree<LL> fw(n);
    rep(i, n) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}
