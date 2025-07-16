#include <stdio.h>

int main() {
	int A, B; 
	scanf("%d %d", &A, &B);
	
	int length = A + B + 1, cnt = 0;
	char S[50];
	scanf("%s", S);
	
	if (S[A] == '-') {
		for(int i = 0; i < length; i++) {
			if (S[i] >= '0' && S[i] <= '9') {
				cnt++;
			}
		}
		if (cnt == length -1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	} else {
			printf("No\n");
		}	
	return 0;
}