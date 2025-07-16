#include <stdio.h>

int dividing(int math, int english, int japanese)
{
	if (math == 100 || english == 100 || japanese == 100) {
		printf("A\n");
	}else if (math + english >= 180) {
		printf("A\n");
	}else if (math + english + japanese >= 240) {
		printf("A\n");
	} else if (math + english + japanese >= 210) {
		printf("B\n");
	} else if (math + english + japanese >= 150 && math >= 80) {
		printf("B\n");
	} else if (math + english + japanese >= 150 && english >= 80) {
		printf("B\n");
	} else {
		printf("C\n");
	}
}

int main(void)
{
	while (1) {
		int number;
		scanf("%d", &number);
		if (number == 0) {
			break;
		}
		for (int i = 0; i < number; i++) {
			int math;
			int english;
			int japanese;
			scanf("%d %d %d", &math, &english, &japanese);
			dividing(math, english, japanese);
		}
	}
}