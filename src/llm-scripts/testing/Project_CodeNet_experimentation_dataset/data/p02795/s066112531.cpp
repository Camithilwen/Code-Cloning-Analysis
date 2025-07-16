#include <stdio.h>
int main ()
{
	int H, W, N;
	scanf ("%d", &H);
	scanf ("%d", &W);
	scanf ("%d", &N);
	if (H < W)
	{
		H=W;
	}
	if (N % H == 0){
		printf ("%d", N/H);
	}
	else if (N % H != 0){
		printf ("%d", (N/H) + 1);
	}
return 0;
}