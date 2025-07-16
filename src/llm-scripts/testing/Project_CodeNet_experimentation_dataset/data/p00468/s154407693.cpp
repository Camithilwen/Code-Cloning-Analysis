#include <cstdio>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
bool used[500];
vector<int> e[500];

int main(){
	while(scanf("%d%d", &n, &m), n||m){
		rep(i,500) e[i].clear();
		rep(i,500) used[i] = false;
		rep(i,m){
			int x, y; scanf("%d%d", &x, &y);
			x--; y--;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		used[0] = true;
		rep(i,e[0].size()){
			used[e[0][i]] = true;
			rep(j,e[e[0][i]].size()){
				used[e[e[0][i]][j]] = true;
			}
		}
		int ans = -1;
		rep(i,500) ans += used[i];
		printf("%d\n", ans);
	}
}