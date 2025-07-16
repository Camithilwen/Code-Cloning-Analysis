#include <stdio.h>
#include <vector>

using namespace std;

int main(void){
	while(true){
		int n, m, t1, t2;
		scanf("%d\n%d", &n, &m);
		if(n == 0 && m == 0) return 0;

		vector< vector<int> > G;

		for(int i = 0;i < n;++i){
			vector<int> V;
			G.push_back(V);
		}

		for(int i = 0;i < m;++i){
			scanf("%d %d", &t1, &t2);
			G[t1-1].push_back(t2-1);
			G[t2-1].push_back(t1-1);
		}

		vector<int> guests(n, 0);

		for(int i = 0;i < G[0].size();++i){
			guests[G[0][i]] = 1;
			for(int j = 0;j < G[G[0][i]].size();++j){
				guests[G[G[0][i]][j]] = 1;
			}
		}

		int c = 0;
		for(int i = 1;i < n;++i){
			c += guests[i];
		}

		printf("%d\n", c);
	}
}
