#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;

// Binary Indexed Tree (Fenwick Tree)
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    // read input as range 
    vector<pair<int, int>> clr_rng;
    {
        unordered_map<int, int> prepos;
        rep(i, 1, N+1)
        {
            int c;
            cin >> c;
            clr_rng.emplace_back(prepos[c], i);
            prepos[c] = i;
        }
    }
    vector<tuple<int, int, int>> qry;
    rep(i, 0, Q)
    {
        int l, r;
        cin >> l >> r;
        qry.emplace_back(l, r, i);
    }


    // sort by start pos 
    sort(clr_rng.rbegin(), clr_rng.rend());
    sort(qry.rbegin(), qry.rend());

    // countint with bit
    BIT<ll> bit(N+1);
    vector<int> ans(Q);
    int pos_c = 0;
    int pos_q = 0;
    rrep(pos, N+1, 1)
    {
        // add range
        while (pos_c < (int) clr_rng.size())
        {
            int frm, to;
            tie(frm, to) = clr_rng[pos_c];
            if (frm < pos) break;

            // printf("from: %d, to: %d\n", frm, to);

            bit.add(to, 1);
            ++pos_c;
        }

        // process query
        while (pos_q < (int) qry.size())
        {
            int frm, to, i;
            tie(frm, to, i) = qry[pos_q];
            if (frm < pos) break;

            int num = to - frm + 1;
            num -= bit.sum(to);

            // printf("from: %d, to: %d, i: %d, bit: %lld\n", frm, to, i, bit.sum(to));

            ans[i] = num;
            ++pos_q;
        }

    }

    // output answer
    rep(i, 0, Q) printf("%d\n", ans[i]);

    return 0;
}
