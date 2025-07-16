#ifndef _TEMPLATE_ROOT
#define _TEMPLATE_ROOT
#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repl(i, a, b) for(ll i = a; i < (b); ++i)
#define repd(i, a, b) for(int i = a; i >= (b); --i)
#define repdl(i, a, b) for(ll i = a; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
#endif
#ifndef _TEMPLATE_IO
#define _TEMPLATE_IO

template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void writef(T ...tail) { write(tail...); cout << flush; }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  if (v.size()) {
    rep(i, 0, sz(v) - 1)
      out << v[i] << " ";
    out << v.back();
  }
  return out;
}
#endif
#ifndef _TEMPLATE_SEGTREE
#define _TEMPLATE_SEGTREE

#ifndef _TEMPLATE_MONOID
#define _TEMPLATE_MONOID
template<class T>
struct Monoid {
	T id;
	virtual T op(T a, T b) = 0;
};
#endif
template<typename T, typename M, typename = enable_if<is_base_of<Monoid<T>, M>::value>>
struct SegTree {
	M monoid;
	vector<T> tree;
	int size;
	SegTree(vector<T> elems, M monoid) : size(elems.size()), monoid(monoid) {
		tree = vector<T>(2 * size);
		for (int i = 0; i < size; i++)
			tree[size + i] = elems[i];
		build();
	}
	SegTree(int size, M monoid) : size(size), monoid(monoid) {
		tree = vector<T>(2 * size, monoid.id);
		build();
	}	
	void build() {
		for (int i = size - 1; i > 0; --i)
			tree[i] = monoid.op(tree[i << 1], tree[i << 1 | 1]);
	}
	T query(int l, int r) {
		T resl = monoid.id, resr = monoid.id;
		++r; // handle inclusive query range
		for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = monoid.op(resl, tree[l++]);
			if (r & 1) resr = monoid.op(tree[--r], resr);
		}
		return monoid.op(resl, resr);
	}
	T get(int p) {
		return tree[size + p];
	}
	void update(int p, T val) {
		for (tree[p += size] = val; p >>= 1;)
			tree[p] = monoid.op(tree[p << 1], tree[p << 1 | 1]);
	}
};
#endif
using namespace std;

struct Query {
  int l, r, id, ans;
};

struct SegTreeAdd : public Monoid<int> {
  int id = 0;
  int op(int a, int b) { return a + b; }
};

int n, q;
int c[500005];
Query p[500005];
int lst[500005];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  read(n, q);
  rep(i, 1, n + 1) read(c[i]);
  rep(i, 1, q + 1) read(p[i].l, p[i].r), p[i].id = i;
  sort(p + 1, p + q + 1, [](const Query& p1, const Query& p2) {
    return p1.r < p2.r;
  });

  SegTree<int, SegTreeAdd> segtree(n + 1, SegTreeAdd());
  int curr = 0;
  rep(i, 1, q + 1) {
    while (p[i].r > curr) {
      ++curr;
      if (lst[c[curr]])
        segtree.update(lst[c[curr]], 0);
      lst[c[curr]] = curr;
      segtree.update(lst[c[curr]], 1);
    }
    p[i].ans = segtree.query(p[i].l, p[i].r);
  }

  sort(p + 1, p + q + 1, [](const Query& p1, const Query& p2) {
    return p1.id < p2.id;
  });

  rep(i, 1, q + 1)
    write(p[i].ans);
}

