#include <stdio.h>

#define LL long long
#define ULL unsigned long long
#define UI unsigned int
#define UC unsigned char
#define UL unsigned long

int main() {
	LL llMax = 1000000000000001, llN;
	scanf("%lld", &llN);
	//a = 97
	int iChar[20], iCnt = 0;
	llN--;
	while (iCnt < 20) {
		iChar[iCnt++] = llN % 26;
		if (llN < 26)
			break;
		llN -= (iChar[iCnt - 1] + 1);
		llN /= 26;
		//printf("%lld\n", llN);
	}
	while (iCnt-- > 0) {
		printf("%c", (char)(iChar[iCnt] + 97));
	}

	return 0;
}
