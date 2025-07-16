#include <iostream>
#include <vector>
#include <functional>
using namespace std;
const int INF = 1001001001;

template<class M, class L> struct LazyPropagationSegmentTree
{
	int n;
	int size;
	vector<M> data;
	vector<L> lazy;
	const function<M(M, M)> f_m;
	const M e_m;
	const function<L(L, L)> f_l;
	const L e_l;
	const function<M(M, L)> f;

	LazyPropagationSegmentTree(int n, function<M(M, M)> f_m, M e_m, function<L(L, L)> f_l, L e_l, function<M(M, L)> f) : n(n), f_m(f_m), e_m(e_m), f_l(f_l), e_l(e_l), f(f) {
		size = 1;
		while (size < n) size <<= 1;
		data.assign(size * 2, e_m);
		lazy.assign(size * 2, e_l);
	}

	void init(const vector<M> &init_vals) {
		data.assign(size * 2, e_m);
		for (int i = 0; i < init_vals.size(); i++) data[size+i] = init_vals[i];
		for (int i = size-1; i > 0; i--) data[i] = f_m(data[2*i], data[2*i+1]);
	}

	void eval(int k) {
		if (lazy[k] == e_l) return;
		if (k < size) {
			lazy[2*k] = f_l(lazy[2*k], lazy[k]);
			lazy[2*k + 1] = f_l(lazy[2*k + 1], lazy[k]);
		}
		data[k] = f(data[k], lazy[k]);
		lazy[k] = e_l;
	}

	void update(int l, int r, L l_prop) {
		update_aux(l, r, l_prop, 1, 0, size);
	}

	void update_aux(int l, int r, L l_prop, int k, int k_l, int k_r) {
		eval(k);
		if (r <= k_l || k_r <= l) return;
		else if (l <= k_l && k_r <= r) {
			lazy[k] = f_l(lazy[k], l_prop);
			eval(k);
		} else {
			update_aux(l, r, l_prop, 2*k, k_l, (k_l + k_r) / 2);
			update_aux(l, r, l_prop, 2*k + 1, (k_l + k_r) / 2, k_r);
			data[k] = f_m(data[2*k], data[2*k + 1]);
		}
	}

	M query(int l, int r) {
		return query_aux(l, r, 1, 0, size);
	}

	M query_aux(int l, int r, int k, int k_l, int k_r) {
		eval(k);
		if (r <= k_l || k_r <= l) return e_m;
		else if (l <= k_l && k_r <= r) return data[k];
		else {
			M vl = query_aux(l, r, k*2, k_l, (k_l + k_r) / 2);
			M vr = query_aux(l, r, k*2 + 1, (k_l + k_r) / 2, k_r);
			return f_m(vl, vr);
		}
	}

	void eval_all() {
		for (int i = 1; i < 2*size; i++) eval(i);
	}

	M val(int idx) {
		return data[size + idx];
	}

	vector<M> val_vec() {
		vector<M> res(n);
		for (int i = 0; i < n; i++) res[i] = data[size+i];
		return res;
	}
};

int main() {
	int h, w;
	cin >> h >> w;
	struct M
	{
		int val, idx, l;
	};
	using L = int;
	M e_m = {-INF, INF, -1};
	L e_l = -INF-1;
	auto f_m = [&](M m1, M m2) -> M {
		if (m1.idx - m1.val < m2.idx - m2.val) return m1;
		else return {m2.val, m2.idx, m1.l};
	};
	auto f_l = [&](L l1, L l2) -> L {
		if (l2 == e_l) return l1;
		return l2;
	};
	auto f = [&](M m, L l) -> M {
		if (l == e_l) return m;
		return {l, m.l, m.l};
	};
	LazyPropagationSegmentTree<M, L> st(w, f_m, e_m, f_l, e_l, f);
	vector<M> init_vals(w);
	for (int i = 0; i < w; i++) {
		init_vals[i] = {i, i, i};
	}
	st.init(init_vals);
	for (int i = 1; i <= h; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		int val;
		if (a == 0) val = -INF;
		else val = st.query(a-1, a).val;
		st.update(a, b, val);
		M q = st.query(0, w);
		int ans = i + q.idx - q.val;
		if (q.val == -INF) ans = -1;
		cout << ans << endl;
	}
	return 0;
}