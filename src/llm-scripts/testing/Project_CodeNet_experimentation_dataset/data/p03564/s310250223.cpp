#include <stdio.h>
 
int main() {
    
	int N=0, K= 0, z= 1;
	scanf("%d\n%d", &N, &K);
	for (int i = 0; i < N; i++) {
		if (2 * z <= z + K) {
			z *= 2;
		} else {
			z += K;
		}
	}
 
	printf("%d\n", z);
    return 0;
}