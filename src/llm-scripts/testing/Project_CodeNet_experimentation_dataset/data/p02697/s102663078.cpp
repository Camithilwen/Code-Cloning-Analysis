#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	int N, M;
	scanf("%d %d", &N, &M);

	int A = M + 2;
	int B = M + 1;
	int C = 2*M + 2;
	for(int i=1, j=0; j < M; i++){
		printf("%d %d\n", i, A - i);
		if(++j < M){
			printf("%d %d\n", B + i, C - i);
			j++;
		}
	}
	return 0;
}