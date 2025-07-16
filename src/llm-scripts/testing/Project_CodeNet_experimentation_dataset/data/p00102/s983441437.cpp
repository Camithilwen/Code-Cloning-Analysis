#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int **array;
	int n;
	
	while(1){
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		
		array = (int **)calloc(n+1, sizeof(int));
		for(int i = 0; i <= n; i++){
			array[i] = (int *)calloc(n+1, sizeof(int));
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &array[i][j]);
				
				array[i][n] += array[i][j];
			}
		}
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < n; j++){
				array[n][i] += array[j][i];
			}
			array[n][n] += array[n][i];
		}
		array[n][n] /= 4;
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				printf("%5d", array[i][j]);
			}
			printf("\n");
		}
		
		for(int i = 0; i <= n; i++){
			free(array[i]);
		}
		free(array);
	}
	
	
	return 0;
}