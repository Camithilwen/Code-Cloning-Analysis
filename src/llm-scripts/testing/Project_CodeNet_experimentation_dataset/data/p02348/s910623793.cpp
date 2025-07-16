#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

template <class operator_monoid> class dual_segment_tree{
public:
	typedef typename operator_monoid::underlying_type underlying_type;
	typedef typename operator_monoid::value_type value_type;
	size_t n;
	vector<underlying_type> v;
	vector<value_type> w;
	underlying_type e = operator_monoid::unit();
	dual_segment_tree(size_t size){
		n = 1;
		while(n < size) n <<= 1;
		v.resize(2*n, e);
		w.resize(size, operator_monoid::default_value());
	}
	dual_segment_tree(vector<value_type> _w){
		size_t size = w.size();
		n = 1;
		while(n < size) n <<= 1;
		v.resize(2*n, e);
		w(_w);
	}
	void range_operate(underlying_type f, size_t a, size_t b, size_t k, size_t l, size_t r){
		if(r <= a || b <= l) return;
		if(a <= l && r <= b) v[k] = operator_monoid::compose(f, v[k]);
		else{
			if(2*k < v.size())
				v[2*k] = operator_monoid::compose(v[k], v[2*k]);
			if(2*k+1 < v.size())
				v[2*k+1] = operator_monoid::compose(v[k], v[2*k+1]);
			v[k] = operator_monoid::unit();
			range_operate(f, a, b, 2*k, l, (l+r+1)/2);
			range_operate(f, a, b, 2*k+1, (l+r+1)/2, r);
		}
	}
	void range_operate(underlying_type f, size_t a, size_t b){
		range_operate(f, a, b, 1, 0, n);
	}
	value_type point_get(size_t i){
		range_operate(e, i, i+1, 1, 0, n);
		return operator_monoid::operate(v[i+n], w[i]);
	}
};
struct assign_operator_monoid{
	using underlying_type = pair<bool, Int>;
	using value_type = Int;
	static underlying_type unit(){
		return pair<bool, int>(true, 0);
	}
	static underlying_type compose(underlying_type l, underlying_type r){
		if(l == unit()) return r;
		return l;
	}
	static value_type default_value(){
		return (1ll<<31)-1;
	}
	static value_type operate(underlying_type f, value_type x){
		return f.first ? x : f.second;
	}
};

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	Int n, q; cin >> n >> q;
	dual_segment_tree<assign_operator_monoid> dst(n);
	while(q--){
		Int p; cin >> p;
		if(p == 0){
			Int s, t, x; cin >> s >> t >> x;
			dst.range_operate(pair<bool, Int>(false, x), s, t+1);
		}else{
			Int i; cin >> i;
			cout << dst.point_get(i) << "\n";
//			if(i == 5)
//				for(Int j=0; j<64; ++j)
//					cout << j << " " << (dst.v[j].first ? "id" : "no") << " " << dst.v[j].second << "\n";
		}
	}
}
