#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	int n, m, **a, s, t, c, *b;
	
	while(1){
		cin >> n;
		cin >> m;
		if(n == 0 && m == 0){
			break;
		}
		c = 0;
		a = (int **)calloc(n+1, sizeof(int));
		b = (int *)calloc(n+1, sizeof(int));
		for(int i = 0; i <= n; i++){
			a[i] = (int *)calloc(n+1, sizeof(int));
		}
		
		for(int i = 0; i < m; i++){
			cin >> s >> t;
			if(s == 1 || t == 1){
				a[s][t] = a[t][s] = 1;
				b[t] = b[s] = 1;
			} else {
				a[s][t] = a[t][s] = 2;
			}
		}
		
		for(int i = 2; i <= n; i++){
			if(a[1][i] == 1){
				for(int j = 2; j <= n; j++){
					if(a[i][j] == 2 && b[j] == 0){
						b[j] = 1;
					}
				}
			}
		}
		b[1] = 0;
		for(int i = 0; i <= n; i++){
			free(a[i]);
			c += b[i];
		}
		free(a);
		free(b);
		
		cout << c << endl;
	}
	
	return 0;
}