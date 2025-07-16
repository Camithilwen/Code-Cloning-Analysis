#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5;
const int posp[4] = {3, 2, 1, 0}, negp[4] = {1, 0, 3, 2}, parp[4] = {2, 3, 0, 1};
const bool post[4] = {1, 1, 0, 0}, negt[4] = {0, 1, 1, 0}, part[4] = {1, 1, 0, 0};

int n, x[N + 1], y[N + 1], u[N + 1], id[256], ans = 0x7fffffff;
char c;
vector<int> pos[4][N * 2 + 1], neg[4][N * 2 + 1], par[4][N + 1];
vector<int>::iterator it;

int main(){
	id['U'] = 0, id['R'] = 1, id['D'] = 2, id['L'] = 3;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d %c", x + i, y + i, &c);
		u[i] = id[c];
		if(u[i] == 0 || u[i] == 2)
			par[u[i]][x[i]].push_back(y[i]);
		else par[u[i]][y[i]].push_back(x[i]);
		pos[u[i]][N + y[i] - x[i]].push_back(x[i]);
		neg[u[i]][x[i] + y[i]].push_back(x[i]);
	}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j <= N; j++)
			sort(par[i][j].begin(), par[i][j].end());
	for(int i = 0; i < 4; i++)
		for(int j = N * 2; ~j; j--){
			sort(pos[i][j].begin(), pos[i][j].end());
			sort(neg[i][j].begin(), neg[i][j].end());
		}
	for(int i = 1; i <= n; i++){
		if(u[i] == 0 || u[i] == 2){
			if(part[u[i]]){
				if(par[parp[u[i]]][x[i]].size() && par[parp[u[i]]][x[i]].back() > y[i])
					ans = min(ans, *lower_bound(par[parp[u[i]]][x[i]].begin(), par[parp[u[i]]][x[i]].end(), y[i]) - y[i]);
			}else if(par[parp[u[i]]][x[i]].size() && par[parp[u[i]]][x[i]].front() < y[i])
				ans = min(ans, y[i] - *--lower_bound(par[parp[u[i]]][x[i]].begin(), par[parp[u[i]]][x[i]].end(), y[i]));
		}else{
			if(part[u[i]]){
				if(par[parp[u[i]]][y[i]].size() && par[parp[u[i]]][y[i]].back() > x[i])
					ans = min(ans, *lower_bound(par[parp[u[i]]][y[i]].begin(), par[parp[u[i]]][y[i]].end(), x[i]) - x[i]);
			}else if(par[parp[u[i]]][y[i]].size() && par[parp[u[i]]][y[i]].front() < x[i])
				ans = min(ans, x[i] - *--lower_bound(par[parp[u[i]]][y[i]].begin(), par[parp[u[i]]][y[i]].end(), x[i]));
		}
		if(post[u[i]]){
			if(pos[posp[u[i]]][N + y[i] - x[i]].size() && pos[posp[u[i]]][N + y[i] - x[i]].back() > x[i])
				ans = min(ans, (*lower_bound(pos[posp[u[i]]][N + y[i] - x[i]].begin(), pos[posp[u[i]]][N + y[i] - x[i]].end(), x[i]) - x[i]) * 2);
		}else if(pos[posp[u[i]]][N + y[i] - x[i]].size() && pos[posp[u[i]]][N + y[i] - x[i]].front() < x[i])
			ans = min(ans, (x[i] - *--lower_bound(pos[posp[u[i]]][N + y[i] - x[i]].begin(), pos[posp[u[i]]][N + y[i] - x[i]].end(), x[i])) * 2);
		if(negt[u[i]]){
			if(neg[negp[u[i]]][x[i] + y[i]].size() && neg[negp[u[i]]][x[i] + y[i]].back() > x[i])
				ans = min(ans, (*lower_bound(neg[negp[u[i]]][x[i] + y[i]].begin(), neg[negp[u[i]]][x[i] + y[i]].end(), x[i]) - x[i]) * 2);
		}else if(neg[negp[u[i]]][x[i] + y[i]].size() && neg[negp[u[i]]][x[i] + y[i]].front() < x[i])
			ans = min(ans, (x[i] - *--lower_bound(neg[negp[u[i]]][x[i] + y[i]].begin(), neg[negp[u[i]]][x[i] + y[i]].end(), x[i])) * 2);
	}
	if(ans == 0x7fffffff) printf("SAFE");
	else printf("%d", ans * 5);
	return 0;
}