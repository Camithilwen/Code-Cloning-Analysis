#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int bipart[maxn];
int color[maxn];
std::vector<int> adj[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int v, e;
	std::cin >> v >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	memset(bipart, -1, sizeof(bipart));
	memset(color, -1, sizeof(color));

	ll single = 0;
	ll nonbipartite = 0;
	ll bipartite = 0;

	for(int i = 0; i < v; i++){
		if(bipart[i] == -1){
			std::queue<int> q;

			bipart[i] = 1;
			int size = 0;
			q.push(i);
			color[i] = 0;

			while(!q.empty()){
				int fr = q.front();
				size++;
				q.pop();

				for(int next : adj[fr]){
					if(color[next] == -1){
						bipart[next] = 0;
						color[next] = !color[fr];
						q.push(next);
					} else if(color[next] == color[fr]){
						bipart[i] = 0;
					}
				}
			}

			if(size == 1){
				single++;
			} else if(bipart[i]){
				bipartite++;
			} else {
				nonbipartite++;
			}
		}
	}

	ll sum = 0;
	sum += (ll) 2 * v * single;
	sum -= single * single;

	sum += 2 * bipartite * bipartite;
	sum += 2 * bipartite * nonbipartite;
	sum += nonbipartite * nonbipartite;

	std::cout << sum << '\n';
}
