#include <iostream>
#include <stdlib.h>
#define inf 99999

using namespace std;

bool check(int *label, int n)
{
	for(int i = 1; i <= n; i++){
		if(label[i] == 0){
			return true;
		}
	}
	
	return false;
}

void dij(int **a, int n, int s, int t)
{
	int *label, current=s, num=1, next, *cost, min;
	
	cost = (int *)calloc(n+1, sizeof(int));
	label = (int *)calloc(n+1, sizeof(int));
	
	for(int i = 1; i <= n; i++){
		cost[i] = a[current][i];
	}
	label[current] = num++;
	
	while(check(label, n)){
		min = inf;
		for(int i = 1; i <= n; i++){
			if(min >= cost[i] && label[i] == 0){
				min = cost[i];
				next = i;
			}
		}
		label[next] = num++;
		for(int i = 1; i <= n; i++){
			if(label[i] == 0 && cost[i] > (a[next][i]+cost[next])){
				cost[i] = a[next][i] + cost[next];
			}
		}
		current = next;
	}
	cout << cost[t] << endl;
	
	free(cost);
	free(label);
	
	return ;
}

int main(int argc, char **argv)
{
	int **t, **c, n, m, a, b, p, q;
	
	while(1){
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		
		t = (int **)calloc(m+1, sizeof(int));
		c = (int **)calloc(m+1, sizeof(int));
		for(int i = 0; i <= m; i++){
			t[i] = (int *)calloc(m+1, sizeof(int));
			c[i] = (int *)calloc(m+1, sizeof(int));
		}
		
		for(int i = 0; i < n; i++){
			cin >> a >> b >> p >> q;
			c[a][b] = c[b][a] = p;
			t[a][b] = t[b][a] = q;
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				if(i != j && c[i][j] == 0){
					c[i][j] = inf;
				}
				if(i != j && t[i][j] == 0){
					t[i][j] = inf;
				}
			}
		}
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a >> b >> p;
			if(p == 0){
				dij(c, m, a, b);
			} else {
				dij(t, m, a, b);
			}
		}
		
		for(int i = 0; i <= m; i++){
			free(t[i]);
			free(c[i]);
		}
		free(t);
		free(c);
	}
	
	return 0;
}