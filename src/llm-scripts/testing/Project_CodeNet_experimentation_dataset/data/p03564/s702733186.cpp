#include <stdio.h>
 
int main() {
    
	int x=0, y= 0, z= 1;
	scanf("%d\n%d", &x, &y);
	for (int i = 0; i < x; i++) {
		if (2 * z <= z + y) {
			z *= 2;
		} else {
			z += y;
		}
	}

	printf("%d\n", z);
    return 0;
}