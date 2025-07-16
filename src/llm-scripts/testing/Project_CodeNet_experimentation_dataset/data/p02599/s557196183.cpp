#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

using P = pair<int,int>;

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main()
{
    int n,Q;
    cin >> n >> Q;
    vector<int> c(n);
    rep(i,n) {
        cin >> c[i];
        c[i]--;
    }
    vector<int> ql(Q),qr(Q);
    vector<vector<int>> table(n);
    rep(i,Q) {
        cin >> ql[i] >> qr[i];
        ql[i]--; qr[i]--;
        table[qr[i]].push_back(ql[i]);
    }

    vector<int> place(n,-1);
    BinaryIndexedTree<int> bit(n);

    map<P,int> mp;
    rep(i,n) {
        if(place[c[i]] != -1) bit.add(place[c[i]], -1);
        place[c[i]] = i;
        bit.add(i, 1);
        for(int l : table[i]) {
            if(l > 0) mp[P(l,i)] = bit.sum(i) - bit.sum(l-1);
            else mp[P(0,i)] = bit.sum(i);
        }
    }

    rep(i,Q) cout << mp[P(ql[i],qr[i])] << endl;
    return 0;
}