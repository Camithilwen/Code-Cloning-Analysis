#include <cstdio>
#include <map>

using namespace std;

typedef pair<int, int> pii;

int c[101][101] = { { 0 } };
int t[101][101] = { { 0 } };
int n, m;

int calculate(int mat[101][101], int from, int to){
	multimap<int, int> locations;
	for(int i = 1; i <= m; i++){
		if(mat[from][i] != 0){
			locations.insert(pii(mat[from][i], i));
		}
	}
	while(!locations.empty()){
		multimap<int, int>::iterator it = locations.begin();
		int d = (*it).first, f = (*it).second;
		if(f == to){ break; }
		for(int i = 1; i <= m; i++){
			if(mat[f][i] != 0 && (d + mat[f][i] < mat[from][i] || mat[from][i] == 0)){
				int dist = d + mat[f][i];
				mat[from][i] = mat[i][from] = dist;
				locations.insert(pii(dist, i));
			}
		}
		locations.erase(it);
	}
	return mat[from][to];
}

int main(){
	while(true){
		scanf("%d%d", &n, &m);
		if(n == 0 || m == 0){ break; }
		for(int i = 0; i <= m; i++){
			for(int j = 0; j <= m; j++){
				c[i][j] = t[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++){
			int a, b, cost, time;
			scanf("%d%d%d%d", &a, &b, &cost, &time);
			if(c[a][b] == 0 || c[a][b] > cost){ c[a][b] = c[b][a] = cost; }
			if(t[a][b] == 0 || t[a][b] > time){ t[a][b] = t[b][a] = time; }
		}
		int k;
		scanf("%d", &k);
		while(k--){
			int p, q, r;
			scanf("%d%d%d", &p, &q, &r);
			printf("%d\n", calculate((r == 0) ? c : t, p, q));
		}
	}
	return 0;
}