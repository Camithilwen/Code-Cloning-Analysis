#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[1000];
bool v[1000];
int s, prevv[1000], n, m, x, y;
void dfs(int cur){
	v[cur] = true;
	for (auto e : a[cur]){
		if (e == s){
			prevv[e] = cur;
		}
		if (!v[e]){
			prevv[e] = cur;
			dfs(e);
		}
	}
}
vector<int> optimize(vector<int> p){
	bool b[n];
	fill(b, b + n, false);
	for (int i = 0; i < p.size(); i++) b[p[i]] = true;
	for (int i = 0; i < p.size(); i++){
		int temp = i - 1;
		if (i == 0) temp = p.size() - 1;
		for (auto e : a[p[i]]){
			if (b[e] && e != p[temp]){
				vector<int> np;
				np.emplace_back(p[i]);
				int cur = i;
				while (p[cur] != e){
					cur++;
					if (cur == p.size()) cur = 0;
					np.emplace_back(p[cur]);
				}
				return optimize(np);
			}
		}
	}
	return p;
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		a[x - 1].emplace_back(y - 1);
	}
	for (s = 0; s < n; s++){
		fill(v, v + n, false);
		fill(prevv, prevv + n, -1);
		dfs(s);
		if (prevv[s] != -1){
			vector<int> p;
			p.emplace_back(s);
			int cur = prevv[s];
			while (cur != s){
				p.emplace_back(cur);
				cur = prevv[cur];
			}
			vector<int> bruh = optimize(p);
			printf("%d\n", bruh.size());
			for (int i = 0; i < bruh.size(); i++) printf("%d\n", bruh[i] + 1);
			return 0;
		}
	}
	printf("-1\n");
}