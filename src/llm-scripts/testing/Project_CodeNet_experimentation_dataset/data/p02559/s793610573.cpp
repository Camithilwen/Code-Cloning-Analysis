#include <iostream>
#include <vector>
#include <functional>

template<typename T> struct segment_tree {
private :
	int N;
	std::vector<T> value;
public :
	const std::function<T(T, T)> op;
	const T id;

	segment_tree(const std::vector<T>& a, const std::function<T(T, T)>& f, const T& t) : op(f), id(t) {
		int n = a.size(), m = 1;
		while (m < n) m *= 2;
		value.resize((N = m) * 2, id);
		for (int i = 0; i < n; i++) value[N + i] = a[i];
		for (int i = N - 1; i > 0; i--) value[i] = op(value[i * 2], value[i * 2 + 1]);
	}

	segment_tree(const int& n, const std::function<T(T, T)>& f, const T& t) : op(f), id(t) {
		int m = 1;
		while (m < n) m *= 2;
		value.resize((N = m) * 2, id);
	}

	inline const int& size()const{return N;}

	void point_update(int i, const std::function<T(T, T)>& f, const T& t) {
		i += N;
		value[i] = f(value[i], t);
		while (i /= 2) value[i] = op(value[i * 2], value[i * 2 + 1]);
	}

	T range_fold(const int& L, const int& R, const int& i = 1, const int& l = 0, int r = -1) {
		if (r == -1) r = N;
		if (L <= l && r <= R) return value[i];
		if (r <= L || R <= l) return id;
		return op(
			range_fold(L, R, i * 2, l, (l + r) / 2),
			range_fold(L, R, i * 2 + 1, (l + r) / 2, r)
		);
	}

	inline const T& operator[](const int& i)const{return value[N + i];}
};

int main() {
	int n, q;
	std::cin >> n >> q;
	std::vector<long long> a(n);
	for (int i = 0; i < n; i++) std::cin >> a[i];

	segment_tree<long long> sg(a, [](long long a, long long b){return a + b;}, 0);
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 0) {
			int p; long long x;
			std::cin >> p >> x;
			sg.point_update(p, [](long long a, long long b){return a + b;}, x);
		} else {
			int l, r;
			std::cin >> l >> r;
			std::cout << sg.range_fold(l, r) << '\n';
		}
	}

	return 0;
}