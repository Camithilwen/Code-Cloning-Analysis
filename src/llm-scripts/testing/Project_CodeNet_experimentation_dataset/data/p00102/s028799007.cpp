#include <cstdio>

int main(){
	int n, table[20][20];

	while( scanf("%d", &n) , n ){
		for(int i=0 ; i<20 ; i++){
			for(int j=0 ; j<20 ; j++){
				table[i][j] = 0;
			}
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				scanf("%d", &table[i][j]);
			}
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				table[i][n] += table[i][j];
				table[n][j] += table[i][j];
			}
		}
		for(int i=0 ; i<n ; i++){
			table[n][n] += table[n][i];
		}
		for(int i=0 ; i<=n ; i++){
			for(int j=0 ; j<=n ; j++){
				printf("%5d", table[i][j]);
			}
			printf("\n");
		}

	}

	return 0;
}