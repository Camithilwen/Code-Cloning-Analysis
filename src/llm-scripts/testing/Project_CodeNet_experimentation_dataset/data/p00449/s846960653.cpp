#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX 10000000

int b[110];
bool used[110];
struct edge{int from, to, cost;};

int solve(int a[110][110], int n, int s, int e){
	fill(b, b+110, MAX);
	fill(used, used+110, false);
	b[s] = 0;
	while(1){
		int v = -1;
		for(int i = 1;i <= n;i++){
			if(!used[i] && (v == -1 || b[v] > b[i]))v = i;
		}
		if(v == -1)break;
		used[v] = true;
		for(int i = 1;i <= n;i++){
			if(a[v][i] != -1)b[i] = min(b[i], b[v] + a[v][i]);
		}
	}
	return 0;
}

int main(){
	int a[110][110], n, k;
	
	while(cin >> n >> k, k){
		fill((int*)a, (int*)(a+110), -1);
		int c, d, e, f;
		for(int i = 0;i < k;i++){
			cin >> c;
			if(c == 0){
				cin >> d >> e;
				solve(a, n, d, e);
				if(b[e] != MAX)cout << b[e] << endl;
				else cout << -1 << endl;
			}else {
				cin >> d >> e >> f;
				if(a[d][e] > f || a[d][e] == -1)
				a[d][e] = a[e][d] = f;
			}
		}
		
	}
	
	return 0;
}