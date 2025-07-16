#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree_lazy {
	int n;
	vector<T> tree, lazy;
	T def = numeric_limits<T>::max(), none = -1;
	
	segtree_lazy(int n_) {
		for (n = 1; n < n_; n *= 2) {
			
		}
		tree.assign(2 * n, def);
		lazy.assign(2 * n, none);
	}
	
	T merge(T a, T b) {
		return max(a, b);
	}
	
	void set_lazy(int index, T x) {
		tree[index] = x;
		lazy[index] = x;
	}
	
	void push(int index) {
		if (lazy[index] == none) {
			return;
		}
		set_lazy(2 * index, tree[index]);
		set_lazy(2 * index + 1, tree[index]);
		lazy[index] = none;
	}
	
	void fix(int index) {
		tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
	}
	
	void update(int a, int b, int index, int l, int r, T x) {
		if (r <= a || b <= l) {
			return;
		}
		if (a <= l && r <= b) {
			set_lazy(index, x);
			return;
		}
		push(index);
		update(a, b, 2 * index, l, (l + r) / 2, x);
		update(a, b, 2 * index + 1, (l + r) / 2, r, x);
		fix(index);
	}
	
	void update(int l, int r, T x) {
		update(l, r, 1, 0, n, x);
	}
	
	T query(int a, int b, int index, int l, int r) {
		if (r <= a || b <= l) {
			return none;
		}
		if (a <= l && r <= b) {
			return tree[index];
		}
		push(index);
		T puni = query(a, b, 2 * index, l, (l + r) / 2);
		T muni = query(a, b, 2 * index + 1, (l + r) / 2, r);
		return merge(puni, muni);
	}
	
	T query(int l, int r) {
		return query(l, r, 1, 0, n);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	segtree_lazy<int> seg(n);
	for (int i = 0; i < q; i++) {
		bool b;
		cin >> b;
		if (b) {
			int x;
			cin >> x;
			cout << seg.query(x, x + 1) << endl;
		} else {
			int s, t, x;
			cin >> s >> t >> x;
			seg.update(s, t + 1, x);
		}
	}
	return 0;
}