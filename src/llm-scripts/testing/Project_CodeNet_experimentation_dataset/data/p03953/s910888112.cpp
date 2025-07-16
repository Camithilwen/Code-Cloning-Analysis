#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; scanf("%d", &n);
	std::vector<i64> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	i64 m, k; scanf("%lld%lld", &m, &k);
	std::vector<int> b(m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		
		b[i]--;
	}
	
	std::vector<i64> d(n - 1);
	for(int i = 0; i < d.size(); i++) d[i] = a[i + 1] - a[i];
	
	std::vector<int> op(d.size());
	for(int i = 0; i < op.size(); i++) op[i] = i;
	for(auto v: b) std::swap(op[v - 1], op[v]);
	
	std::vector<int> ret(d.size());
	for(int i = 0; i < d.size(); i++) ret[i] = i;
	std::function<void ()> solve = [&]() {
		while(k) {
			if(k & 1) {
				std::vector<int> tmp(ret.size());
				for(int i = 0; i < op.size(); i++) {
					tmp[i] = ret[op[i]];
				}
				ret.swap(tmp);
			}
			
			std::vector<int> nxt = op;
			for(int i = 0; i < op.size(); i++) {
				nxt[i] = op[op[i]];
			}
			op.swap(nxt);
			k >>= 1;
		}
	};
	solve();
	
	std::vector<i64> ans(n, 0); ans[0] = a[0];
	for(int i = 0; i < ret.size(); i++) ans[i + 1] = d[ret[i]];
	for(int i = 0; i < ret.size(); i++) ans[i + 1] += ans[i];
	
	for(auto v: ans) printf("%lld\n", v);
	return 0;
}
